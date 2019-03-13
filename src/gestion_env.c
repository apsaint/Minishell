/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 08:53:49 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/13 11:38:03 by apsaint-         ###   ########.fr       */
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

int		add_var_env(t_env *env, char *var)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = ft_strchr(var, '=');
	while (var[i] != '=')
		i++;
	if ((env->name = (char *)malloc(sizeof(env->name) * i)) == NULL)
		return (ALLOC_ERROR);
	ft_strncpy(env->name, var, i);
	env->value = ft_strdup(++ptr);
	return (0);
}

void	free_env(t_envlist *env_list)
{
	free(env_list->data);
	ft_memset(env_list, 0, sizeof(env_list));
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
		add_var_env(&env_list.data[env_list.count++], env[i++]);
	return (0);
}
