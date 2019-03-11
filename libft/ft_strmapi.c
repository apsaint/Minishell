/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:29:44 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/15 11:33:59 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*cpy;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if ((cpy = (char *)malloc(sizeof(*cpy) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	while (*s)
	{
		cpy[i] = f(i, *s);
		s++;
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
