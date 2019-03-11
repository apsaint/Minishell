/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:57:18 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/15 12:23:34 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_longnum(int n)
{
	int i;

	i = 0;
	if (n < 0 || n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_longnum(n);
	if ((str = ft_memalloc(i + 1)) == NULL)
		return (NULL);
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[--i] = '8';
			n /= 10;
		}
		n = -n;
	}
	while (i-- && n > 9)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	if (str[i] != '-')
		str[i] = n + '0';
	return (str);
}
