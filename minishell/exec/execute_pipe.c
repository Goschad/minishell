/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:44:42 by marvin            #+#    #+#             */
/*   Updated: 2023/12/10 02:44:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void pipeline_cut(int i, int *fd, int *pipefd, int n_step)
{
    int fdd;

    if (i != 0)
    {
        dup2(*fd, 0);
        close(*fd);
    }
    if (i != n_step)
    {
        dup2(pipefd[1], 1);
        close(pipefd[0]);
        close(pipefd[1]);
    }
}

// leaks shell->p_cmd

void execute_pipeline(t_shell *shell, int i, int j, int input_fd)
{
    pid_t pid;
    int pipefd[2];

    while (++i <= shell->pipl.n_steps - 1)
    {
        if (i != shell->pipl.n_steps - 1)
            pipe(pipefd);
        pid = fork();
        if (pid == 0)
        {
            pipeline_cut(i, &input_fd, pipefd, shell->pipl.n_steps - 1);
            shell_execve(shell->cmd[i], shell->env, shell);
        }
        if (i != 0)
            close(input_fd);
        if (i != shell->pipl.n_steps - 1)
            ((void)0, close(pipefd[1]), input_fd = pipefd[0]);
    }
    while (++j <= shell->pipl.n_steps - 1) 
        wait(NULL);
}