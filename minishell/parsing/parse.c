/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 04:09:26 by mbouaza           #+#    #+#             */
/*   Updated: 2023/11/15 22:24:40 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// *cmd << mdp > file

// open check les autorisation du fichier

static void token(char **cmds, int i)
{
	if (!ft_strcmp(cmds[i], "<<"))
		printf("%s : herdoc redir\n", cmds[i]);
	else if (!ft_strcmp(cmds[i], "||"))
		printf("%s : or\n", cmds[i]);
	else if (!ft_strcmp(cmds[i], "&&"))
		printf("%s : and\n", cmds[i]);
	else if (!ft_strcmp(cmds[i], "<"))
		printf("%s : redir\n", cmds[i]);
	else if (!ft_strcmp(cmds[i], ">"))
		printf("%s : redir (remplace)\n", cmds[i]);
	else if (!ft_strcmp(cmds[i], ">>"))
		printf("%s : redir (add)\n", cmds[i]);
	else if (!ft_strcmp(cmds[i], "|"))
		printf("%s : pipe\n", cmds[i]);
	else
		printf("%s : str\n", cmds[i]);
}

static void debug(char *readed)
{
	printf("---------------------- info ----------------------\n");
	// printf("• quotes parse = %s\n", quoted_line(readed));
	// printf("• space rebuid parse = %s\n", rebuild_space_line(readed, 0, 0));
	// printf("• quotes parse = %s\n", var_conversion(readed));
	// printf("• pipe number = %d\n", count_pipe(readed));
	// printf("• or number = %d\n", count_or(readed));
	printf("--------------------------------------------------\n");
}

void parse(char *readed, t_shell *shell)
{
	int i;

	i = 0;
	debug(readed);

	shell->all = cut_cmd(readed); 
	shell_execve(shell);
	tab_free(shell->all);
}