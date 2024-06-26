/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:08:03 by jguerin           #+#    #+#             */
/*   Updated: 2024/05/08 16:08:03 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	pipeline_cut(int i, int *fd, int *pipefd, t_shell *sh)
{
	int	n_steps;

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
	if (redir(sh, -1) != FALSE)
	{
		find_bull(sh, sh->p_cmd, i);
	}
	else
	{
		tab_free(sh->p_cmd);
		exit(1);
	}
	tab_free(sh->p_cmd);
	sh->p_cmd = NULL;
}

static char	*converte_line(char *line, int i, int j)
{
	char	*newline;
	int		in_q;

	newline = NULL;
	in_q = 0;
	while (line[++i])
	{
		if (!update(line[i], &in_q))
			j++;
	}
	newline = malloc(sizeof(char) * j + 1);
	i = -1;
	j = 0;
	in_q = 0;
	while (line[++i])
	{
		if (!update(line[i], &in_q))
			newline[j++] = line[i];
	}
	newline[j] = '\0';
	return (newline);
}

static void	parse_quotes(t_shell *sh)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_tabdup(sh->p_cmd);
	if (!tab)
		return ;
	tab_free(sh->p_cmd);
	sh->p_cmd = NULL;
	sh->p_cmd = malloc(sizeof(char *) * (env_len(tab) + 1));
	while (tab[i])
	{
		sh->p_cmd[i] = converte_line(tab[i], -1, 0);
		i++;
	}
	sh->p_cmd[i] = NULL;
	tab_free(tab);
	return ;
}

static void	pid_cut(t_shell *shell, pid_t *pid, int i)
{
	g_var = 1;
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

void	execute_pipeline(t_shell *shell, int i, int j, int input_fd)
{
	pid_t	pid;
	int		pipefd[2];

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
		wait(NULL);
		if (shell->forked_cmd == 1)
			shell->status = WEXITSTATUS(shell->var.i);
	}
}
