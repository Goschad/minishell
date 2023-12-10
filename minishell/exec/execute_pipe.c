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

// leaks shell->p_cmd

void execute_pipeline(t_shell *shell, int i, int j, int input_fd)
{
    int pipefd[2];

    while (++i <= shell->pipeline.n_steps - 1)
    {
        if (i != shell->pipeline.n_steps - 1)
            pipe(pipefd);
        if (fork() == 0)
        {
            if (i != 0)
                ((void)0, dup2(input_fd, 0), close(input_fd));
            if (i != shell->pipeline.n_steps - 1)
                ((void)0, dup2(pipefd[1], 1),
                    close(pipefd[0]), close(pipefd[1]));
            shell_execve(shell->cmd[i], shell->env, shell);
        }
        if (i != 0)
            close(input_fd);
        if (i != shell->pipeline.n_steps - 1)
            ((void)0, close(pipefd[1]), input_fd = pipefd[0]);
    }
    while (++j <= shell->pipeline.n_steps - 1) 
        wait(NULL);
}