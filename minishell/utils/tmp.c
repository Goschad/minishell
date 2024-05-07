/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 07:07:00 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/30 07:16:20 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
    return (0);
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

void	print_tab(char **tab)
{
	for (int i = 0; tab[i]; i++)
		printf("%s\n", tab[i]);
}