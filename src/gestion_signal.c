/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 08:38:44 by apsaint-          #+#    #+#             */
/*   Updated: 2019/04/09 09:23:04 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	gestion_sig(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr("\nminishell> ");
		signal(SIGINT, gestion_sig);
	}
}

void	gestion_sig_cmd(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar('\n');
		signal(SIGINT, gestion_sig_cmd);
	}
}
