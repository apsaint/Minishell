/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:42:28 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/13 12:37:21 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		my_echo(char **av)
{
	int		i;
	int		opt;

	i = 1;
	if (av[1])
	{
		if (ft_strcmp(av[1], "-n") == 0)
			i = 2;
	}
	else
		return (0);
	opt = i;
	while (av[i])
	{
		if ((i > 1 && opt == 1) || (i > 2 && opt == 2))
			ft_putchar(' ');
		ft_putstr(av[i++]);
	}
	if (opt == 1)
		ft_putchar('\n');
	return (0);
}
