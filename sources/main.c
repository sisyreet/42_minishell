/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:07:07 by sisyreet          #+#    #+#             */
/*   Updated: 2022/05/24 17:07:12 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_str(char *line, t_env *env)
{
	if (!ft_strncmp("env", line, 3))
		print_env(env);
	if (!ft_strncmp("exit", line, 4))
		ft_exit (0);
	if (!ft_strncmp("cd", line, 2))
		ft_cd(env, &line[3]);
	if (!ft_strncmp("echo -n ", line, 8))
		ft_echo(&line[8], 1);
	else if (!ft_strncmp("echo ", line, 5))
		ft_echo(&line[5], 0);
	return (0);
}

int	prompt(t_env *env, char *line)
{
	while (1)
	{
		line = readline("minishell> ");
		if (check_str(line, env))
			return (1);
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
