/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:29:15 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/16 08:49:54 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*cpylst;

	cpylst = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	if (lst != NULL)
	{
		if ((cpylst = (t_list *)ft_memalloc(sizeof(t_list))) == NULL)
			return (NULL);
		cpylst = f(lst);
		cpylst->next = ft_lstmap(lst->next, f);
	}
	return (cpylst);
}
