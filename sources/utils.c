/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:20:13 by sisyreet          #+#    #+#             */
/*   Updated: 2022/05/24 14:50:21 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_error(char *message)
{
	write(2, message, ft_strlen(message));
	exit (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_w_size(const char *s1, size_t size)
{
	int		i;
	char	*str;

	str = malloc(size * sizeof(char) + 1);
	if (!str)
		return (0);
	i = 0;
	while (size)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
