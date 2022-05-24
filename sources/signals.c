/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:55:08 by sisyreet          #+#    #+#             */
/*   Updated: 2022/05/20 13:17:45 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	signal_handler(int signum)
{
}

int	signals(void)
{
	struct sigaction	siga;

	siga.sa_flags = SA_SIGINFO;
	siga.sa_handler = signal_handler;
	sigaction(SIGINT, &siga, NULL);
	sigaction(EOF, &siga, NULL);
	sigaction(SIGQUIT, &siga, NULL);
	return (0);
}
