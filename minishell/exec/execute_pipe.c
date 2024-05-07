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

static int add_argc(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

static void pipeline_cut(int i, int *fd, int *pipefd, t_shell *sh)
{
    int n_steps;

    n_steps = sh->pipl.n_steps - 1;
    if (i != 0)
    {
        dup2(*fd, 0);
        close(*fd);
    }
    if (i != n_steps)
    {
        dup2(pipefd[1], 1);
        close(pipefd[0]);
        close(pipefd[1]);
    }
    redir(sh, -1);
    find_bull(sh, sh->p_cmd, i);
    tab_free(sh->p_cmd);     
    sh->p_cmd = NULL;
} 

static void parse_quotes(t_shell *sh)
{
    int i;
    char **tab;

    i = 0;
    tab = ft_tabdup(sh->p_cmd);
    tab_free(sh->p_cmd);
    sh->p_cmd = malloc(sizeof(char *) * env_len(tab) + 1);
    while (tab[i])
    {
        sh->p_cmd[i] = quoted_line(tab[i]);
        i++;
    }
    sh->p_cmd[i] = NULL;
    tab_free(tab);
}

static void pid_cut(t_shell *shell, pid_t *pid, int i)
{
    shell->p_cmd = cut_cmd(shell->cmd[i]);
    parse_quotes(shell);
	shell->argc = add_argc(shell->p_cmd);
    shell->forked_cmd = isnt_bull(shell, shell->p_cmd);
    if (shell->forked_cmd == 1)
        *pid = fork();
    else
        *pid = 0;
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
        pid_cut(shell, &pid, i);
        if (pid == 0)
            pipeline_cut(i, &input_fd, pipefd, shell);
        else
            tab_free(shell->p_cmd);
        if (i != 0)
            close(input_fd);
        if (i != shell->pipl.n_steps - 1)
            ((void)0, close(pipefd[1]), input_fd = pipefd[0]);
    }
    while (++j <= shell->pipl.n_steps - 1)
    {
        waitpid(pid, &shell->var.i, WIFEXITED(pid));
        if (shell->forked_cmd == 1)
		    shell->status = WEXITSTATUS(shell->var.i);
    }
}
