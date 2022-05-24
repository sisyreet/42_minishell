/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:52:56 by sisyreet          #+#    #+#             */
/*   Updated: 2022/05/18 13:31:58 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{	
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	*malloc_word(char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

int	splitter(char *str, char c, char **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			arr[j] = malloc_word((char *)&str[i], c);
			if (!arr[j])
			{				
				ft_free(arr);
				return (1);
			}
			j++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	arr[j] = 0;
	return (0);
}

char	**ft_split(char const *str, char c)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	arr = (char **)malloc(sizeof(char *) * (count_words((char *)str, c) + 1));
	if (!arr)
		return (0);
	if (splitter((char *)str, c, arr))
	{
		free(arr);
		return (0);
	}
	return (arr);
}
