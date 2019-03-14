/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 08:53:49 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/14 09:58:58 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_table_size(char **env)
{
	int		i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

static int	resize_array(t_envlist *env_list)
{
	const int	new_size_in_bytes = sizeof(t_env) * (f_list->size += 2);
	const int	bytes_to_copy = sizeof(t_env) * f_list->count;
	t_env		*tmp_array;

	if ((tmp_array = (t_env *)malloc(new_size_in_bytes)) == NULL)
		return (ALLOC_ERROR);
	ft_memcpy(tmp_array, env_list->data, bytes_to_copy);
	free(env_list->data);
	env_list->data = tmp_array;
	return (0);
}

int		add_var_env(t_env *env, char *var, char *name)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!name)
	{
		ptr = ft_strchr(var, '=');
		while (var[i] != '=')
			i++;
		ft_strncpy(env->name, var, i);
		ft_strcpy(env->value, ++ptr);
	}
	else
	{
		ft_strcpy(env_name, name);
		ft_strcpy(env_value, var);
	}
	return (0);
}

void	free_env(t_envlist *env_list)
{
	free(env_list->data);
	ft_memset(env_list, 0, sizeof(env_list));
}

int		find_env_var(char *str)
{
	int i;

	i = 0;
	while (i < env_list.size)
	{
		if (ft_strcmp(str, env_list.data[i].name) == 0)
			return (i);
		i++;
	}
	return (ENV_ERROR);
}

int		copy_venv(char **env)
{
	int		size;
	int		i;

	size = get_table_size(env);
	i = 0;
	if ((env_list.data = (t_env *)malloc(sizeof(t_env) * (size + 1))) == NULL)
			return (ALLOC_ERROR);
	ft_memset(env_list.data, 0, sizeof(t_env) * (size + 1));
	env_list.count = 0;
	env_list.size = size;
	while (env_list.count != size)
		add_var_env(&env_list.data[env_list.count++], env[i++], NULL);
	return (0);
}
