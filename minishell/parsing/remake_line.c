/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remake_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 05:45:11 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/26 11:05:44 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	change_whitespace(char *readed)
{
	int	i;

	i = 0;
	while (readed[i])
	{
		if (readed[i] == '\t')
			readed[i] = ' ';
		i++;
	}
}

static char	*token_while(char *readed)
{
	char	*after;
	char	*tmp;

	after = NULL;
	tmp = NULL;
	after = readline("> ");
	if (!after || !ft_strcmp("", after))
		return (ft_strdup(readed));
	tmp = ft_join(readed, after);
	free(after);
	return (tmp);
}

static int	check_eol(char *readed)
{
	int	i;

	i = ft_strlen(readed) - 1;
	if (readed[i] == '\n')
		readed[i--] = '\0';
	while (i > 0 && readed[i] == ' ')
		i--;
	if (i > 0)
	{
		if (readed[i] == '|')
			return (0);
		else if (readed[i] == '&' && readed[i - 1] == '&')
			return (0);
	}
	return (1);
}

void	change_nl(char *readed)
{
	int	i;

	i = 0;
	while (readed[i])
	{
		if (readed[i] == '\n')
			readed[i] = '\0';
		i++;
	}
}

char	*reboot_line(char *readed)
{
	char	*cpy;
	char	*readd;

	cpy = NULL;
	readd = NULL;
	if (!readed || !ft_strcmp("", readed))
		return (ft_strdup(readed));
	readd = ft_strdup(readed);
	change_whitespace(readd);
	while (!check_eol(readd))
	{
		cpy = ft_strdup(readd);
		free(readd);
		readd = token_while(cpy);
		free(cpy);
	}
	return (readd);
}
