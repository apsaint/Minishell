/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_switch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:29:31 by apsaint-          #+#    #+#             */
/*   Updated: 2019/04/05 13:27:26 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		run(pid_t proc, char *path, char **cmd, char **n_env)
{
	if (proc == 0)
		execve(path, cmd, n_env);
	else if (proc < 0)
	{
		ft_putendl("Fork failed");
		return (FORK_ERROR);
	}
	return (0);
}

int		exe_cmd(char *path_cmd, char **cmd, char **n_env)
{
	struct stat		fs;
	pid_t			new_proc;

	if (stat(path_cmd, &fs) == -1)
		return (ARG_ERROR);
	else
	{
		if (fs.st_mode & S_IFREG)
		{
			if (fs.st_mode & S_IXUSR)
			{
				new_proc = fork();
				run(new_proc, path_cmd, cmd, n_env);
				wait(&new_proc);
			}
			else
			{
				ft_putstr("minishell: permission denied : ");
				ft_putendl(cmd[0]);
			}
		}
		return (0);
	}
}

int		search_exe(char *path, char **cmd, char **n_env)
{
	DIR				*dirp;
	struct dirent	*dp;
	char			full_path[4097];
	int				ret;

	ft_bzero(full_path, sizeof(full_path));
	if ((dirp = opendir(path)) == NULL)
		return (ARG_ERROR);
	else
	{
		while ((dp = readdir(dirp)) != NULL)
		{
			if (ft_strcmp(dp->d_name, cmd[0]) == 0)
			{
				ft_strlcat(full_path, path, 4097);
				ft_strlcat(full_path, "/", 4097);
				ft_strlcat(full_path, dp->d_name, 4097);
				ret = exe_cmd(full_path, cmd, n_env);
				closedir(dirp);
				return (ret);
			}
		}
	}
	closedir(dirp);
	return (1);
}

int		course_path(char **cmd, char **n_env, int ind)
{
	char	**path;
	char	**tmp;
	int		ret;
	int		i;

	i = -1;
	tmp = ft_strsplit(n_env[ind], '=');
	path = ft_strsplit(tmp[1], ':');
	while (path[++i])
	{
		if ((ret = search_exe(path[i], cmd, n_env)) == 0)
		{
			free_tab(tmp);
			free_tab(path);
			free_tab(cmd);
			if (n_env)
				free_tab(n_env);
			return (ret);
		}
	}
	free_tab(tmp);
	free_tab(path);
	return (1);
}

int		search_path(char **cmd, char *str, char **n_env)
{
	int		ret;
	char	c[4097];
	int		ind;

	if (!cmd[0])
		return (free_tab(cmd));
	get_pwd(c, cmd);
	if (exe_cmd(c, cmd, n_env) != -1)
	{
		if (n_env != NULL)
			free_tab(n_env);
		return (free_tab(cmd));
	}
	else if ((ind = find_env_path(str, n_env)) != -1)
	{
		if ((ret = course_path(cmd, n_env, ind)) == 0)
			return (ret);
	}
	ft_putstr("minishell: ");
	ft_putstr(cmd[0]);
	ft_putendl(": No such file or directory");
	if (n_env != NULL)
		free_tab(n_env);
	return (free_tab(cmd));
}
