/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kos <kos@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:13:21 by sisyreet          #+#    #+#             */
/*   Updated: 2022/05/27 15:12:37 by kos              ###   ########.fr       */
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
			printf(">>> %s-%s\n", temp->name, temp->value);
			temp->value = new_value;
			printf("here!\n");
			printf(">>> %s-%s\n", temp->name, temp->value);
			return ;
		}	
		temp = temp->next;
	}
	//add_new_var(env->head, var_name, new_value);
}

void	add_new_var(t_list *head, char *var_name, char *value)
{
	t_list	*ptr;
	t_list	*temp;
	
	ptr = head;
	temp = malloc(sizeof(t_list));
	if (!temp)
		ft_error("Memory allocation failed!\n");
	temp->name = var_name;
	temp->value = value;
	temp->next = NULL;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = temp;
}