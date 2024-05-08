/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:34:40 by mbouaza           #+#    #+#             */
/*   Updated: 2024/05/08 09:07:54 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int identifie(char *token, int before)
{
    if (before == REDIR_D_LEFT)
        return (HEREDOC_PASS);
    else if (!ft_strcmp(token, "<<"))
        return (REDIR_D_LEFT);
    else if (!ft_strcmp(token, ">>"))
        return (REDIR_D_RIGHT);
    else if (!ft_strcmp(token, ">"))
        return (REDIR_RIGHT);
    else if (!ft_strcmp(token, "<"))
        return (REDIR_LEFT);
    else if (before == REDIR_D_RIGHT || before == REDIR_RIGHT
        || before == REDIR_LEFT)
        return (FILE);
    else
        return (UNKNOWN);
}

void heredoc(char *pass)
{
    int		fd;
    char	*line;

    signal(SIGINT, SIG_DFL);
	rl_catch_signals = 1;
	fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0777);;
	while (1)
	{
		line = readline("> ");
        if (!line)
             break;
        if (!ft_strcmp(pass, line))
        {
            free(line);
			break ;
        }
		write(fd, line, sizeof(char) * ft_strlen(line));
		write(fd, "\n", 1);
        free(line);
	}
	close(fd);
    exit(0);
}