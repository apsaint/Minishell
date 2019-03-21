/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_switch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:29:31 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/21 11:59:43 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		run(pid_t proc, char *path, char **cmd)
{
	char	**cp_env;

	if (proc == 0)
	{
		cp_env = cpy_env();
		execve(path, cmd, cp_env);
	}
	else if (proc < 0)
	{
		ft_putendl("Fork failed");
		return (FORK_ERROR);
	}
	return (0);
}

int		exe_cmd(char *path_cmd, char **cmd)
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
				run(new_proc, path_cmd, cmd);
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

int		search_exe(char *path, char **cmd)
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
				ret = exe_cmd(full_path, cmd);
				closedir(dirp);
				return (ret);
			}
		}
	}
	closedir(dirp);
	return (1);
}

int		search_path(char **cmd)
{
	int		i;
	char	**path;
	int		ret;

	i = 0;
	path = ft_strsplit(env_list.data[find_env_var("PATH")].value, ':');
	while (path[i])
	{
		if ((ret = search_exe(path[i], cmd)) == 0)
		{
			free_tab(path);
			free_tab(cmd);
			return (ret);
		}
		else
			i++;
	}
	ft_putstr(cmd[0]);
	ft_putendl(": command not found");
	free_tab(path);
	free_tab(cmd);
	return (0);
}

int		switch_command(char *c)
{
	char	**cmd;
	//char	**tab;

	//cmd = ft_strsplit(c, ' ');
	cmd = ft_strsplit_input(c, ' ');
	if (ft_strcmp(cmd[0], "exit") == 0)
	{
		free_tab(cmd);
		return (-1);
	}
	else if (ft_strcmp(cmd[0], "cd") == 0)
		return (my_cd(cmd));
	else if (ft_strcmp(cmd[0], "echo") == 0)
		return (my_echo(cmd));
	else if (ft_strcmp(cmd[0], "env") == 0)
	{
		free_tab(cmd);
		return (print_env());
	}
	else if (ft_strcmp(cmd[0], "setenv") == 0)
		return (my_set_env(cmd));
	else if (ft_strcmp(cmd[0], "unsetenv") == 0)
		return (my_unset_env(cmd));
	else
		return (search_path(cmd));
	return (0);
}
