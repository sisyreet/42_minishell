/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_and_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:11:56 by sisyreet          #+#    #+#             */
/*   Updated: 2022/05/24 17:08:30 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	get_env_vars(char **envp, t_env *env)
{
	int		i;
	char	**temp;

	i = 0;
	while (envp[i])
		i++;
	env->num_of_env_vars = i;
	env->env_vars = malloc(sizeof(t_var) * i + 1);
	i = 0;
	while (i < env->num_of_env_vars)
	{
		temp = ft_split(envp[i], '=');
		env->env_vars[i].name = temp[0];
		env->env_vars[i].value = temp[1];
		free(temp);
		i++;
	}
}

void	print_env(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->num_of_env_vars)
	{
		write(1, env->env_vars[i].name, ft_strlen(env->env_vars[i].name));
		write(1, "=", 1);
		write(1, env->env_vars[i].value, ft_strlen(env->env_vars[i].value));
		write(1, "\n", 1);
		i++;
	}
}
