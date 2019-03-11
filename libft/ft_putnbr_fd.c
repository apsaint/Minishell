/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:25:29 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/15 12:26:02 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int tmp;

	if ((n + 1) == -2147483647)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n > 2147483647 || n < -2147483648)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		tmp = n % 10;
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(tmp + '0', fd);
	}
	if (n < 10 && n >= 0)
		ft_putchar_fd(n + '0', fd);
}
