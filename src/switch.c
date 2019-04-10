/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 10:34:51 by apsaint-          #+#    #+#             */
/*   Updated: 2019/04/09 11:13:59 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_pwd(char *c, char **cmd)
{
	if (cmd[0][0] == '.')
	{
		getcwd(c, 4097);
		ft_strlcat(c, "/", 4097);
		ft_strlcat(c, cmd[0], 4097);
	}
	else if (cmd[0][0] == '/')
		ft_strcpy(c, cmd[0]);
	return (0);
}

int		switch_command(char *c)
{
	char	**cmd;

	cmd = ft_strsplit_input(c, ' ');
	if (cmd[0] && ft_strcmp(cmd[0], "exit") == 0)
	{
		free_tab(cmd);
		return (-1);
	}
	else if (cmd[0] && ft_strcmp(cmd[0], "cd") == 0)
		return (my_cd(cmd));
	else if (cmd[0] && ft_strcmp(cmd[0], "echo") == 0)
		return (my_echo(cmd));
	else if (cmd[0] && ft_strcmp(cmd[0], "env") == 0)
		return (my_env(cmd));
	else if (cmd[0] && ft_strcmp(cmd[0], "setenv") == 0)
		return (my_set_env(cmd));
	else if (cmd[0] && ft_strcmp(cmd[0], "unsetenv") == 0)
		return (my_unset_env(cmd));
	else if (cmd[0])
		return (search_path(cmd, "PATH", cpy_env()));
	free_tab(cmd);
	return (0);
}
