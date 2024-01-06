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

void find_bull(t_shell *shell, char **cmd, int i)
{
    if (!ft_strcmp(cmd[0], "echo"))
        b_echo(shell, cmd);
    else if (!ft_strcmp(cmd[0], "env"))
        b_env(shell, cmd, shell->env);
    else if (!ft_strcmp(cmd[0], "cd"))
        printf("cd\n");
    else if (!ft_strcmp(cmd[0], "pwd"))
        printf("pwd\n");
    else if (!ft_strcmp(cmd[0], "exit"))
        printf("exit\n");
    else if (!ft_strcmp(cmd[0], "export"))
        printf("export\n");
    else if (!ft_strcmp(cmd[0], "unset"))
        printf("unset\n");
    else
        shell_execve(shell->cmd[i], shell->env, shell);
    exit(shell->status);
}

