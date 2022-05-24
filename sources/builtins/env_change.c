/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:13:21 by sisyreet          #+#    #+#             */
/*   Updated: 2022/05/24 17:06:27 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	while (ft_strncmp(env->env_vars[i].name, var_name, ft_strlen(var_name))) // проверка что такая переменная вообще есть
		i++;
	env->env_vars[i].value = ft_strdup(new_value);
}

void	add_new_env_var(t_env *env, char *var_name)
{
}

void	del_new_env_var(t_env *env, char *var_name)
{
}
