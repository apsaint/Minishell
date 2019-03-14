/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:22:16 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/14 13:25:57 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		my_exit(int status)
{
	if (status)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
