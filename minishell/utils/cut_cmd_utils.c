/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_cmd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:53:11 by GIGI              #+#    #+#             */
/*   Updated: 2024/05/08 17:12:33 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	quotes_cmd_size(char *line)
{
	int	i;
	int	num;
	int	in_q;

	i = 0;
	num = 0;
	in_q = 0;
	while (line[i])
	{
		if (update(line[i], &in_q))
		{
			i++;
			num++;
			while (line[i] && !update(line[i], &in_q))
				i++;
			i++;
		}
		else
			i++;
	}
	return (num);
}

char	**make_cmds(char **av, int pipeline, int i, int j)
{
	char	*tmp2;
	char	*tmp;
	char	*line;
	char	**cmd;

	((void)0, line = NULL, tmp = NULL, tmp2 = NULL, cmd = NULL);
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
			multfree(tmp, tmp2, NULL, NULL);
		}
		if (av[i] && !ft_strcmp(av[i], "|"))
			i++;
		cmd[j++] = ft_strdup(line);
		free(line);
	}
	cmd[j] = NULL;
	return (cmd);
}
