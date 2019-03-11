/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 08:36:40 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/16 12:38:51 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	int		i;
	char	*cpy;

	start = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	end = ft_strlen(s) - 1;
	if (*s == '\0')
		return ((char *)s);
	while ((s[start] == '\n' || s[start] == ' ' || s[start] == '\t'))
		start++;
	while ((s[end] == '\n' || s[end] == ' ' || s[end] == '\t') && end > 0)
		end--;
	if (end == 0 || s[start] == '\0')
		return (ft_strcpy(ft_memalloc(sizeof(char) * 2), ""));
	if ((cpy = (char *)malloc(sizeof(*cpy) * ((end - start) + 2))) == NULL)
		return (NULL);
	while (start <= end)
		cpy[i++] = s[start++];
	cpy[i] = '\0';
	return (cpy);
}
