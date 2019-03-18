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
	return (0);
}
