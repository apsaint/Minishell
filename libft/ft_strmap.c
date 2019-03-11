/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:25:02 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/15 11:31:40 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*cpy;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((cpy = (char *)malloc(sizeof(*cpy) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	while (*s)
	{
		cpy[i] = f(*s);
		s++;
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
