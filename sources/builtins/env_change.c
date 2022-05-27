/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kos <kos@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:13:21 by sisyreet          #+#    #+#             */
/*   Updated: 2022/05/27 09:18:36 by kos              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_new_env_var(t_env *env, char *var_name)
{
}

char	*get_env_var_value(t_env *env, char *var_name)
{
	int	i;

	i = 0;
	while (ft_strncmp(env->env_vars[i].name, var_name, ft_strlen(var_name)))
		i++;
	return (env->env_vars[i].value);
}

void	set_env_var_value(t_env *env, char *var_name, char *new_value)
{
	int		i;

	i = 0;
	while (i < env->num_of_env_vars)
	{
		if (!ft_strncmp(env->env_vars[i].name, var_name, ft_strlen(var_name)))
		{
			env->env_vars[i].value = ft_strdup(new_value);
			return ;
		}	
		i++;
	}
	add_new_env_var(var_name, new_value);
}


void	del_new_env_var(t_env *env, char *var_name)
{
}
