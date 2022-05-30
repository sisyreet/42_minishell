/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:32:14 by sisyreet          #+#    #+#             */
/*   Updated: 2022/05/30 11:43:35 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(t_env *env)
{
	t_list	*temp;

	temp = env->head;
	while (temp)
	{
		if (!ft_strncmp(temp->name, "PWD", 3))
		{
			write(1, temp->value, ft_strlen(temp->value));
			write(1, "\n", 1);
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}
