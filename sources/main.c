/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:07:07 by sisyreet          #+#    #+#             */
/*   Updated: 2022/05/30 15:01:18 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	run_command(char *line, t_env *env)
{
	if (!ft_strncmp("pwd", line, 3) && ft_strlen(line) == 3)
		ft_pwd(env);
	if (!ft_strncmp("cd ", line, 3))
		ft_cd(env, &line[3]);
	if (!ft_strncmp("env", line, 3))
		print_env(env);
	if (!ft_strncmp("export ", line, 7))
		ft_export(env, "kostya", "molodec");
	if (!ft_strncmp("unset ", line, 6))
		ft_unset(env, &line[6]);
	if (!ft_strncmp("exit", line, 4))
		exit (0);
}

int	is_command(char *line)
{
	if (!ft_strncmp("env", line, 3))
		return (1);
	if (!ft_strncmp("exit", line, 4) && ft_strlen(line) == 4)
		return (1);
	if (!ft_strncmp("cd ", line, 3))
		return (1);
	if (!ft_strncmp("echo", line, 4))
		return (1);
	if (!ft_strncmp("export ", line, 7))
		return (1);
	if (!ft_strncmp("pwd", line, 3) && ft_strlen(line) == 3)
		return (1);
	if (!ft_strncmp("unset ", line, 6))
		return (1);
	return (0);
}

int	prompt(t_env *env, char *line)
{
	while (1)
	{
		line = readline("minishell> ");
		if (is_command(line))
			run_command(line, env);
		else
		{
			write(2, "command not found: ", 19);
			write(2, line, ft_strlen(line));
			write(2, "\n", 1);
		}
		add_history(line);
		free(line);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_env	*env;

	(void)argc;
	(void)argv;
	line = 0;
	env = malloc(sizeof(t_env));
	if (!env)
		ft_error("Memory allocation failed!");
	get_env_vars(envp, env);
	using_history();
	while (prompt(env, line))
	{
	}
	free(line);
	return (0);
}
