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

int	isnt_bull(t_shell *shell, char **cmd, int i)
{
	if (!ft_strcmp(cmd[0], "cd") || !ft_strcmp(cmd[0], "exit"))
		return (-1);
	return (1);
}

void	find_bull(t_shell *shell, char **cmd, int i)
{
	t_exit	xt;

	tokenizer(cmd);
	if (!ft_strcmp(cmd[0], "echo"))
		echo(cmd);
	else if (!ft_strcmp(cmd[0], "env"))
		env(shell->env, cmd);
	else if (!ft_strcmp(cmd[0], "cd"))
		ft_cd(cmd, shell);
	else if (!ft_strcmp(cmd[0], "pwd"))
		pwd();
	else if (!ft_strcmp(cmd[0], "exit"))
		ft_exit(cmd, shell, xt);
	else if (!ft_strcmp(cmd[0], "export"))
		printf("export\n");
	else if (!ft_strcmp(cmd[0], "unset"))
		printf("unset\n");
	else
		shell_execve(shell->cmd[i], shell->env, shell);
	if (shell->forked_cmd == 1)
		exit(shell->status);
}
