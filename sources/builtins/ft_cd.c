/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:15:49 by sisyreet          #+#    #+#             */
/*   Updated: 2022/05/30 14:14:00 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_no_such(char *path)
{
	write(2, "cd: no such file or directory: ", 31);
	write(2, path, ft_strlen(path));
	write(2, "\n", 1);
}

void	ft_cd(t_env *env, char *path)
{
	char	*buf;

	buf = malloc(sizeof(char) * 100); //сомнительная хуйня, пересмотреть получение размера буфера
	if (!chdir(path))
	{
		set_env_var_value(env, "OLDPWD", get_env_var_value(env, "PWD"));
		set_env_var_value(env, "PWD", getcwd(buf, 100)); //сомнительная хуйня, пересмотреть получение размера буфура
	}
	else
		print_no_such(path);
}
