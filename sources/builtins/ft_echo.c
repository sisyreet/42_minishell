/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:57:16 by sisyreet          #+#    #+#             */
/*   Updated: 2022/05/20 13:11:20 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_echo(char *line, int flag)
{
	if (line)
	{
		if (flag == 1)
			write(1, line, ft_strlen(line));
		else
		{
			write(1, line, ft_strlen(line));
			write(1, "\n", 1);
		}
	}
	else
		printf("\n");
}
