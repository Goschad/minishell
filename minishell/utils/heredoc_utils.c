/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:13:35 by mbouaza           #+#    #+#             */
/*   Updated: 2024/05/08 17:16:35 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	verif_part1(char *t, char *pass)
{
	int	i;

	i = 0;
	while (ft_strlen(pass) > 1 && t[i])
	{
		if (pass[0] == t[i] && (pass[1] == t[0] || pass[1] == t[1]
				|| pass[1] == t[2] || pass[1] == t[3]))
		{
			ft_error(TOKEN_ERR, NULL, NULL);
			ft_putchar_fd(t[i], 2);
			ft_putchar_fd(pass[1], 2);
			ft_error("'\n", NULL, NULL);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

static int	verif_pass(char *pass, char *t)
{
	int	i;

	i = 0;
	if (!pass)
		return (TRUE);
	if (verif_part1(t, pass) == FALSE)
		return (FALSE);
	while (ft_strlen(pass) >= 1 && t[i])
	{
		if (pass[0] == t[i])
		{
			ft_error(TOKEN_ERR, NULL, NULL);
			ft_putchar_fd(t[i], 2);
			ft_error("'\n", NULL, NULL);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

void	make_heredoc(char **f, int bf)
{
	int	i;

	i = 0;
	while (f[i])
	{
		bf = identifie(f[i], bf);
		if (bf == HEREDOC_PASS)
		{
			heredoc(f[i]);
			bf = -1;
		}
		i++;
	}
}

int	unexpected(int token, char **f)
{
	int	j;

	j = 0;
	while (f[j])
	{
		token = identifie(f[j], token);
		if (token == HEREDOC_PASS)
		{
			if (verif_pass(f[j], "|<>&") == FALSE)
				return (FALSE);
		}
		j++;
	}
	return (TRUE);
}

void	heredoc_priority(int token, char **f)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (f[j])
	{
		token = identifie(f[j], token);
		if (token == HEREDOC_PASS)
			heredoc(f[j]);
		j++;
	}
}
