/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:34:40 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/25 08:51:48 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int identifie(char *token, int before)
{
    if (!ft_strcmp(token, "<<"))
        return (REDIR_D_LEFT);
    else if (!ft_strcmp(token, ">>"))
        return (REDIR_D_RIGHT);
    else if (!ft_strcmp(token, ">"))
        return (REDIR_RIGHT);
    else if (!ft_strcmp(token, "<"))
        return (REDIR_LEFT);
    else if (before == REDIR_D_LEFT)
        return (HEREDOC_PASS);
    else if (before == REDIR_D_RIGHT || before == REDIR_RIGHT)
        return (FILE);
    else
        return (UNKNOWN);
}

// le dernier file doit etre pri en compte
static int prinToken(int token)
{
    if (token == REDIR_D_LEFT)
        printf("[heredoc redir]");
    else if (token == REDIR_D_RIGHT)
        printf("[redir double vers la droite]");
    else if (token == REDIR_LEFT)
        printf("[redir simple gauche]");
    else if (token == REDIR_RIGHT)
        printf("[redir simple droite]");
    else if (token == HEREDOC_PASS)
        printf("[password heredoc]");
    else if (token == FILE)
        printf("[fichier]");
    else
        printf("[inconnu]");
}

void tokenizer(char **test)
{
    int i;
    int before;

    i = 0;
    before = 0;
    while (test[i])
    {
        before = identifie(test[i], before);
        prinToken(before);
        printf(" ");
        i++;
    }
    printf("\n");
}

// askip c le debut

void heredoc(char *pass)
{
	char *line;

	line = NULL;
	while (1)
    {
        line = readline("> ");
        if (!ft_strcmp(line, pass))
            return (free(line));
        free(line);
    }
}