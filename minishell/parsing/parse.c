/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 04:09:26 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/26 11:09:38 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// *cmd << mdp > file

// open check les autorisation du fichier

static void	token(char **cmds, int i)
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

static void	debug(char *readed)
{
	printf("---------------------- info ----------------------\n");
	printf("• quotes parse = %s\n", quoted_line(readed));
	printf("• quotes parse = %s\n", readed);
	// printf("• quotes parse = %s\n", var_conversion(readed));
	printf("--------------------------------------------------\n");
}

static int	count_pipe(char **cmds)
{
	int	n;
	int	i;

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

static char	**make_cmds(char **av, int pipeline, int i, int j)
{
	char	*tmp2;
	char	*tmp;
	char	*line;
	char	**cmd;

	line = NULL;
	cmd = malloc(sizeof(char *) * (pipeline + 1));
	while (av[i])
	{
		line = ft_strdup(av[i++]);
		while (av[i] && ft_strcmp(av[i], "|"))
		{
			tmp = ft_join(line, " ");
			free(line);
			tmp2 = ft_join(tmp, av[i++]);
			line = ft_strdup(tmp2);
			free(tmp);
			free(tmp2);
		}
		if (av[i] && !ft_strcmp(av[i], "|"))
			i++;
		cmd[j++] = ft_strdup(line);
		free(line);
	}
	cmd[j] = NULL;
	return (cmd);
}

void	parse(char *readed, t_shell *shell)
{
	int		i;
	char	**cpy;
	char	*cpyy;

	i = 0;
	// heredoc("test", shell);
	cpy = NULL;
	cpyy = ft_strdup(readed);
	cpyy = env_conversion(cpyy, shell->env, -1, shell);
	change_nl(cpyy);
	shell->all = cut_cmd(cpyy);
	cpy = ft_tabdup(shell->all);
	tab_free(shell->all);
	shell->all = wildcard(cpy);
	shell->pipl.n_steps = count_pipe(shell->all) + 1;
	shell->cmd = make_cmds(shell->all, shell->pipl.n_steps, 0, 0);
	execute_pipeline(shell, -1, -1, 0);
	tab_free(shell->cmd);
	tab_free(shell->all);
	tab_free(cpy);
	free(cpyy);
}
