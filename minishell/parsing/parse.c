/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 04:09:26 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/30 08:06:35 by mbouaza          ###   ########.fr       */
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
	tab = ft_tabdup(sh->all);
	tab_free(sh->all);
	return (tab);
}

static void	pre_v1(char *str, t_shell *sh)
{
	sh->all = cut_cmd(str);
	unexpected(-1, sh->all);
	make_heredoc(sh->all, -1);
	tab_free(sh->all);
}

static void exec(char **tab, t_shell *sh)
{
	sh->all = wildcard(tab);
	sh->pipl.n_steps = count_pipe(sh->all) + 1;
	sh->cmd = make_cmds(sh->all, sh->pipl.n_steps, 0, 0);
	execute_pipeline(sh, -1, -1, 0);
}

void parse(char *readed, int i, t_shell *shell)
{
	char *cpyy;
	char **cpy;
	
	cpy = NULL;
	cpyy = ft_strdup(readed);
	pre_v1(cpyy, shell);
	cpyy = env_conversion(cpyy, shell->env, -1, shell);
	if (banned(cpyy) == FALSE)
		return (free(cpyy));
	cpy = pre_v2(cpyy, shell);
	exec(cpy, shell);
	multfree(cpyy, NULL, shell->cmd, shell->all);
	tab_free(cpy);
}