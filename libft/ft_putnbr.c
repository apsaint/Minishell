/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:27:12 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/13 09:58:14 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int temp;

	if ((n + 1) == -2147483647)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n > 2147483647 || n < -2147483648)
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		temp = n % 10;
		ft_putnbr(n / 10);
		ft_putchar(temp + '0');
	}
	if (n < 10 && n >= 0)
		ft_putchar(n + '0');
}
