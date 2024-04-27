/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:43:04 by marvin            #+#    #+#             */
/*   Updated: 2023/12/21 15:43:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int supp_bin(char *f)
{
	if (f[5] && f[0] == '/' && f[1] == 'b' &&  f[2] == 'i' &&  f[3] == 'n'
		&&  f[4] == '/' && f[5] != '\0')
		return (TRUE);
	return (FALSE);
}

int	isnt_bull(t_shell *shell, char **cmd, int i)
{
	if (supp_bin(cmd[0]) == TRUE || env_len(cmd) > 0)
		return (1);
	if (!ft_strcmp(cmd[0], "cd") || !ft_strcmp(cmd[0], "exit")
		|| !ft_strcmp(cmd[0], "export") || !ft_strcmp(cmd[0], "unset")
		|| command_exists(cmd[0], 0) == FALSE
		|| !ft_strcmp(cmd[0], "env") || !ft_strcmp(cmd[0], "echo")
		|| !ft_strcmp(cmd[0], "pwd"))
		return (-1);
	return (1);
}

void	find_bull(t_shell *shell, char **cmd, int i)
{
	t_exit	xt;

	// tokenizer(cmd);
	set_status(127, shell);
	if (!ft_strcmp(cmd[0], "echo"))
		echo(cmd, shell);
	else if (!ft_strcmp(cmd[0], "env"))
		env(shell->env, cmd, shell);
	else if (!ft_strcmp(cmd[0], "cd"))
		ft_cd(cmd, shell);
	else if (!ft_strcmp(cmd[0], "pwd"))
		pwd(shell);
	else if (!ft_strcmp(cmd[0], "exit"))
		ft_exit(cmd, shell, xt);
	else if (!ft_strcmp(cmd[0], "export"))
		ft_export(cmd, shell->env, shell);
	else if (!ft_strcmp(cmd[0], "unset"))
		ft_unset(cmd, shell->env, shell);
	else
		shell_execve(shell->env, shell);
	if (shell->forked_cmd == 1)
		exit(shell->status);
}
