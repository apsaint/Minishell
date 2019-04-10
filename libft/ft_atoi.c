/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 08:42:50 by apsaint-          #+#    #+#             */
/*   Updated: 2019/04/09 10:41:07 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int neg;
	int nb;

	neg = 0;
	nb = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\b' || *str == '\r' || *str == '\a' || *str == '\f')
		str++;
	if (*str == '-')
		neg = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (str && *str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += (int)(*str - '0');
		str++;
	}
	if (neg == 1)
		return (-nb);
	return (nb);
}
