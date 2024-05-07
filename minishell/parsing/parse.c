/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 04:09:26 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/30 13:12:54 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int count_pipe(char **cmds)
{
	int n;
	int i;

	i = 0;
	n = 0;
	while (cmds[i])
	{
		if (!ft_strcmp(cmds[i], "|"))
			n++;
		i++;
	}
	return (n);
}

static char **pre_v2(char *str, t_shell *sh)
{
	char **tab;

	tab = NULL;
	change_nl(str);
	sh->all = cut_cmd(str);
	print_tab(sh->all);
	tab = ft_tabdup(sh->all);
	tab_free(sh->all);
	return (tab);
}

static int	pre_v1(char *str, t_shell *sh)
{
	sh->all = cut_cmd(str);
	print_tab(sh->all);
	if (unexpected(-1, sh->all) == FALSE || redir_err(sh->all) == FALSE)
		return (tab_free(sh->all), FALSE);
	make_heredoc(sh->all, -1);
	tab_free(sh->all);
	return (TRUE);
}

static void exec(char **tab, t_shell *sh)
{
	sh->all = wildcard(tab);
	sh->pipl.n_steps = count_pipe(sh->all) + 1;
	sh->cmd = make_cmds(sh->all, sh->pipl.n_steps, 0, 0);
	execute_pipeline(sh, -1, -1, 0);
	unlink("./.heredoc");
}

int parse(char *readed, int i, t_shell *shell)
{
	char *cpyy;
	char *ne_cpy;
	char **cpy;
	
	cpy = NULL;
	cpyy = ft_strdup(readed);
	ne_cpy = ft_strdup(readed);
	if (pre_v1(cpyy, shell) == FALSE)
		return (free(ne_cpy),free(cpyy), FALSE);
	cpyy = env_conversion(cpyy, shell->env, -1, shell);
	if (banned(cpyy) == FALSE)
		return (free(ne_cpy), free(cpyy), FALSE);
	cpy = pre_v2(cpyy, shell);
	exec(cpy, shell);
	multfree(cpyy, ne_cpy, shell->cmd, shell->all);
	return (tab_free(cpy), TRUE);
}