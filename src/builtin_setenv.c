/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:34:43 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/14 13:50:08 by apsaint-         ###   ########.fr       */
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

int		remove_env_var(char *name)
{
	int		ind;

	if ((ind = find_env_var(name)) == -1)
	{
		ft_putstr(name);
		ft_putendl(": does not exist in environnement");
		return (ENV_ERROR);
	}
	while (ind < env_list.count)
	{
		ft_strcpy(env_list.data[ind].name, env_list.data[ind + 1].name);
		ft_strcpy(env_list.data[ind].value, env_list.data[ind + 1].value);
		ind++;
	}
	env_list.count--;
	return (0);
}

int		print_env(void)
{
	int i;

	i = 0;
	while (i != env_list.count)
	{
		ft_putstr(env_list.data[i].name);
		ft_putchar('=');
		ft_putendl(env_list.data[i++].value);
	}
	return (0);
}

int		my_set_env(char **cmd)
{
	int i;
	int c;

	i = 1;
	c = 0;
	while (cmd[i++])
		c++;
	if (!c)
		return (print_env());
	else if (c == 2)
		return (set_env_var(cmd[1], cmd[2]));
	else if (c == 1)
		return (set_env_var(cmd[1], NULL));
	else
		ft_putendl("setenv: Too many arguments");
	return (1);
}

int		my_unset_env(char **cmd)
{
	int i;

	i = 1;
	if (!cmd[i])
		ft_putendl("unsetenv: Too few arguments.");
	else
	{
		while (cmd[i])
			remove_env_var(cmd[i++]);
	}
	return (1);
}
