/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:32:02 by sisyreet          #+#    #+#             */
/*   Updated: 2022/05/30 15:15:14 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	delete_last_node(t_list *node)
{
	free(node->next->name);
	free(node->next->value);
	free(node->next);
	node->next = NULL;
}

void	delete_mid_node(t_list *node)
{
	t_list	*temp;

	temp = node->next->next;
	free(node->next->name);
	free(node->next->value);
	free(node->next);
	node->next = temp;
}

int	ft_unset(t_env *env, char *var_name)
{
	t_list	*begin;

	begin = env->head;
	while (begin->next)
	{
		if (!ft_strncmp(begin->next->name, var_name, ft_strlen(var_name)))
		{
			if (!begin->next->next)
				delete_last_node(begin);
			else
				delete_mid_node(begin);
			return (0);
		}
		begin = begin->next;
	}
	return (1);
}
