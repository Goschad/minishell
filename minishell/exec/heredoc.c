/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:34:40 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/26 11:20:11 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	identifie(char *token, int before)
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
static int	print_token(int token)
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

void	tokenizer(char **test)
{
	int	i;
	int	before;

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

static int	ft_sstrlen(char **t1)
{
	int	i;

	i = 0;
	while (t1[i])
		i++;
	return (i);
}

static char	**add_tab(char **copy, char *add, int t)
{
	int		i;
	char	**new;

	if (t == 0)
		i = 0;
	else
		i = ft_sstrlen(copy);
	new = malloc(sizeof(char *) * (i + 2));
	if (!new)
		return (NULL);
	if (t == 0 && add)
	{
		new[0] = ft_strdup(add);
		new[1] = NULL;
		return (new);
	}
	i = 0;
	while (copy[i])
	{
		new[i] = ft_strdup(copy[i]);
		i++;
	}
	if (add == NULL)
		new[i++] = ft_strdup(add);
	new[i] = NULL;
	return (new);
}
// askip c le debut

void	heredoc(char *pass, t_shell *shell)
{
	int		i;
	char	*line;
	char	**cpy;

	cpy = NULL;
	line = NULL;
	i = 0;
	while (1)
	{
		line = readline("> ");
		if (!ft_strcmp(line, pass))
			return (print_tab(shell->heredoc), free(line));
		if (shell->heredoc == NULL)
			shell->heredoc = add_tab(NULL, line, i);
		else
		{
			cpy = add_tab(shell->heredoc, line, i);
			print_tab(cpy);
			tab_free(shell->heredoc);
			shell->heredoc = NULL;
			shell->heredoc = ft_tabdup(cpy);
			tab_free(cpy);
			cpy = NULL;
		}
		i++;
		free(line);
	}
}
