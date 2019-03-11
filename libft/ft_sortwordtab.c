/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortwordtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:10:41 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/16 13:17:01 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sortwordtab(char **tab)
{
	int		i;
	int		min;
	int		j;
	int		n;
	char	*tmp;

	i = -1;
	j = 0;
	n = 0;
	while (tab[n] != 0)
		n++;
	while (++i < (n - 1))
	{
		min = i;
		j = i;
		while (j < n)
		{
			if (ft_strcmp(tab[j], tab[min]) < 0)
				min = j;
			j++;
		}
		tmp = tab[min];
		tab[min] = tab[i];
		tab[i] = tmp;
	}
}
