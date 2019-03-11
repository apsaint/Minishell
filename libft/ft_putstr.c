/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:14:48 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/15 10:16:45 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char	const *s)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		ft_putchar(*s);
		s++;
	}
}
