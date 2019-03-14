/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:34:43 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/14 10:15:22 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		set_env_var(char *name, char *value)
{
	int		i;

	if ((i = find_env_var(name)) != -1)
		ft_strcpy(env_list.data[i].value, value);
	else
	{
		if (env_list.count == env_list.size)
		{
			if (resize_array(&env_list) == ALLOC_ERROR)
				return (ALLOC_ERROR);
		}
		add_var_env(&env_list.data[env_list.count++], value, name);
	}
	return (0);
}
