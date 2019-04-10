/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 08:53:49 by apsaint-          #+#    #+#             */
/*   Updated: 2019/04/09 11:26:09 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		resize_array(t_envlist *g_env_list)
{
	const int	new_size_in_bytes = sizeof(t_env) * (g_env_list->size += 2);
	const int	bytes_to_copy = sizeof(t_env) * g_env_list->count;
	t_env		*tmp_array;

	if ((tmp_array = (t_env *)malloc(new_size_in_bytes)) == NULL)
		return (ALLOC_ERROR);
	ft_memcpy(tmp_array, g_env_list->data, bytes_to_copy);
	free(g_env_list->data);
	g_env_list->data = tmp_array;
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
		ft_strcpy(env->name, name);
		if (var)
			ft_strcpy(env->value, var);
		else
			ft_bzero(env->value, 4097);
	}
	return (0);
}

int		find_env_var(char *str)
{
	int i;
	int	c;

	i = 0;
	c = 1;
	while (i < g_env_list.size)
	{
		if ((c = ft_strcmp(str, g_env_list.data[i].name)) == 0)
			return (i);
		i++;
	}
	return (ENV_ERROR);
}

int		init_venv(int ac, char **av, char **env)
{
	int		size;
	int		i;
	char	*tmp;

	(void)ac;
	(void)av;
	size = get_table_size(env);
	i = 0;
	if ((g_env_list.data = (t_env *)malloc(sizeof(t_env) * (size + 1))) == NULL)
		return (ALLOC_ERROR);
	ft_memset(g_env_list.data, 0, sizeof(t_env) * (size + 1));
	g_env_list.count = 0;
	g_env_list.size = size;
	while (g_env_list.count != size)
		add_var_env(&g_env_list.data[g_env_list.count++], env[i++], NULL);
	if ((i = find_env_var("SHLVL")) != -1)
	{
		tmp = ft_itoa(ft_atoi(g_env_list.data[i].value) + 1);
		ft_strcpy(g_env_list.data[i].value, tmp);
		free(tmp);
	}
	return (0);
}

char	**cpy_env(void)
{
	int		size;
	int		i;
	char	**env;
	char	tmp[4097];

	size = g_env_list.count;
	i = 0;
	if (size == 0)
		return (NULL);
	if ((env = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	while (i != size)
	{
		ft_strcpy(tmp, g_env_list.data[i].name);
		ft_strlcat(tmp, "=", 4097);
		env[i] = ft_strjoin(tmp, g_env_list.data[i].value);
		i++;
	}
	env[i] = NULL;
	return (env);
}
