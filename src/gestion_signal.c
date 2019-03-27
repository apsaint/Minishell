/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 08:38:44 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/27 13:34:32 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	gestion_sig(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr("\nminishell>");
		signal(SIGINT, gestion_sig);
	}
}
