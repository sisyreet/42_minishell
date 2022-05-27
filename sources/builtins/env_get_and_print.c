/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_and_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kos <kos@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:11:56 by sisyreet          #+#    #+#             */
/*   Updated: 2022/05/27 14:50:12 by kos              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	get_env_vars(char **envp, t_env *env)
{
	int		i;
	char	**temp;

	i = 0;
	env->head = malloc(sizeof(t_list));
	if (!env->head)
		ft_error("Memory allocation failed!\n");
	while (envp[i])
	{
		temp = ft_split(envp[i], '=');
		if (i == 0)
		{
			env->head->name = temp[0];
			env->head->value = temp[1];
			env->head->next = NULL;
		}
		else
		{
			add_new_var(env->head, temp[0], temp[1]);
		}
		i++;
		free (temp);
	}		
}

void	print_env(t_env *env)
{
	t_list *temp;
	
	temp = env->head;
	while (temp)
	{
		printf("%s=%s\n", temp->name, temp->value);
		temp = temp->next;
	}
}
