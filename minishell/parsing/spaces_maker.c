/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 02:22:07 by mbouaza           #+#    #+#             */
/*   Updated: 2024/05/08 17:13:20 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// | < << > >>

static int ez(char *r, int i)
{
	if (r && r[i - 1] && r[i] && r[i] == '>' && r[i - 1] != ' '
		&& r[i - 1] != '>')
		return (1);
	if (r && r[i - 1] && r[i] && r[i + 1] && r[i] != ' ' && r[i] != '>'
		&& r[i - 1] == '>' && r[i + 1] != '>')
		return (1);
	if (r && r[i - 1] && r[i] && r[i] == '<' && r[i - 1] != ' '
		&& r[i - 1] != '<')
		return (1);
	if (r && r[i - 1] && r[i] && r[i + 1] && r[i] != ' '
		&& r[i] != '<' && r[i - 1] == '<' && r[i + 1] != '<')
		return (1);
	return (0);
}

static int spaced_verif(char *r, int i, int len)
{
	if (!(i > 0 && i < len - 1))
		return (0);
	if (r && r[i] && r[i + 1] && r[i] == '|' && r[i + 1] != ' ')
		return (1);
	if (r && r[i - 1] && r[i] && r[i] != ' ' && r[i] != '|' && r[i - 1] == '|')
		return (1);
	if (r && i < len - 2 && r[i] && r[i] != ' ')
	{
		if (r[i - 1] && r[i - 1] == '>')
			if (r[i - 2] && r[i - 2] == '>')
				return (1);
	}
	if (r && i < len - 2 && r[i] && r[i] != ' ')
	{
		if (r[i - 1] && r[i - 1] == '<')
			if (r[i - 2] && r[i - 2] == '<')
				return (1);
	}
	return (ez(r, i));
}

static int rebuild_space_len(char *r, int i)
{
	int j;
	int in_q;

	j = 0;
	in_q = 0;
	while (r && r[i])
	{
		if (r[j] && spaced_verif(r, i, ft_strlen(r)))
				((void)0, i++, j++);
		else if (update(r[i], &in_q))
		{
			i++;
			while (r[i] && !update(r[i], &in_q))
				i++;
			i++;
		}
		else
			i++;
	}
	return (i + j);
}

// norm

char *rebuild_space_line(char *r, int j, int in_q)
{
	int i;
	char *new;

	i = 0;
	new = malloc(sizeof(char) * (rebuild_space_len(r, 0) + 1));
	while (r[j])
	{
		if (spaced_verif(r, j, ft_strlen(r)))
		{
			new[i++] = ' ';
			new[i++] = r[j++];
		}
		else if (update(r[j], &in_q))
		{
			new[i++] = r[j++];
			while (r[j] && !update(r[j], &in_q))
				new[i++] = r[j++];
			new[i++] = r[j++];
		}
		else
			new[i++] = r[j++];
	}
	new[i] = '\0';
	return (new);
}