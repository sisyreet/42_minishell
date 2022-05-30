/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:13:21 by sisyreet          #+#    #+#             */
/*   Updated: 2022/05/30 13:25:08 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env_var_value(t_env *env, char *var_name)
{
	t_list	*temp;

	temp = env->head;
	while (ft_strncmp(var_name, temp->name, ft_strlen(var_name)))
		temp = temp->next;
	return (temp->value);
}

void	set_env_var_value(t_env *env, char *var_name, char *new_value)
{
	t_list	*temp;

	temp = env->head;
	while (temp)
	{
		if (!ft_strncmp(var_name, temp->name, ft_strlen(var_name)))
		{
			temp->value = new_value;
			return ;
		}	
		temp = temp->next;
	}
}

void	add_new_var(t_list *head, char *var_name, char *value)
{
	t_list	*ptr;
	t_list	*new_node;

	ptr = head;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		ft_error("Memory allocation failed!\n");
	new_node->name = var_name;
	new_node->value = value;
	new_node->next = NULL;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new_node;
}
