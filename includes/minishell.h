/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:46:54 by sisyreet          #+#    #+#             */
/*   Updated: 2022/05/30 14:57:57 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h> /* del */
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <signal.h>
# include <readline/history.h>

typedef struct s_list
{	
	char			*name;
	char			*value;
	struct s_list	*next;
}	t_list;

typedef struct s_var
{
	char	*name;
	char	*value;
}	t_var;

typedef struct s_env
{
	t_var	*env_vars;
	t_list	*head;
	int		num_of_env_vars;
}	t_env;

void	ft_echo(char *line, int flag);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *str, char c);
void	ft_free(char **arr);
void	ft_error(char *message);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	get_env_vars(char **envp, t_env *my_env);
void	print_env(t_env *my_env);
void	ft_cd(t_env *env, char *path);
int		ft_pwd(t_env *env);
int		ft_export(t_env *env, char *var_name, char *value);
int		ft_unset(t_env *env, char *var_name);
void	add_new_var(t_list *head, char *var_name, char *value);
char	*get_env_var_value(t_env *env, char *var_name);
void	set_env_var_value(t_env *env, char *var_name, char *new_value);
void	ft_exit(char *code);

#endif