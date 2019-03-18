/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_switch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:29:31 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/14 13:29:44 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exe_cmd(char *path_cmd, char **cmd)
{
	struct stat		fs;
	pid_t			new_proc;
	char			**cp_env;

	if (stat(path_cmd, &fs) == -1)
		return (STAT_ERROR);
	else
	{
		if (fs.st_mode & S_IFREG)
		{
			if (fs.st_mode & S_IXUSR)
			{
				new_proc = fork();
				if (new_proc == 0)
				{
					cp_env = cpy_env();
					execve(path_cmd, cmd, cp_env);
				}
				else
				{
					free(new_proc);
					ft_putendl("Fork failed");
					return (FORK_ERROR);
				}
				wait(&new_proc);
				if (new_proc)
					free(new_proc);
			}
			else
				print_error_exe(full_path);
		}
		return (1);
	}
}

int		search_exe(char *path, char **cmd)
{
	DIR				*dirp;
	struct dirent	*dp;
	char			full_path[4097];

	if ((dirp = opendir(path)) == NULL)
		return (ERROR_PATH);
	else
	{
		while (!(dp = readdir(dirp)))
		{
			if (ft_strcmp(dp->name, cmd[0]) == 0)
			{
				full_path = ft_strlcat(path, '/', 4097);
				ft_strlcat(full_path, dp->name, 4097);
				return (exe_cmd(full_path, cmd));
			}
		}
		return (2);
	}
}

int		search_path(char **cmd)
{
	int		i;
	char	**path;
	char	*bin;

	i = 0;
	path_bin = ft_strsplit(env_list.data[find_env_var("PATH")].value, ':');
	while (path_bin[i])
	{
		if ((bin = search_exe(path_bin[i], cmd[0])))
			free(bin);
	}
}

int		switch_command(char **cmd)
{
	if (ft_strcmp(cmd[0], "exit") == 0)
		return (EXIT_STATUS);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		return (my_cd(cmd));
	else if (ft_strcmp(cmd[0], "echo") == 0)
		return (my_echo(cmd));
	else if (ft_strcmp(cmd[0], "env") == 0)
		return (print_env());
	else if (ft_strcmp(cmd[0], "setenv") == 0)
		return (my_set_env(cmd));
	else if (ft_strcmp(cmd[0], "unsetenv") == 0)
		return (my_unset_env(cmd));
	else
		return (exe_intern_bin(cmd));
	return (0);
}
