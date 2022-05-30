/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:59:07 by sisyreet          #+#    #+#             */
/*   Updated: 2022/05/30 13:23:19 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_export(t_env *env, char *var_name, char *value)
{
	t_list	*temp;

	temp = env->head;
	while (temp)
	{
		if (!ft_strncmp(temp->name, var_name, ft_strlen(var_name)))
		{
			set_env_var_value(env, var_name, value);
			return (0);
		}
		temp = temp->next;
	}
	add_new_var(env->head, var_name, value);
	return (1);
}
