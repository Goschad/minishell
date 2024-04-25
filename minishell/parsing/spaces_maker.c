/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 02:22:07 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/25 08:17:05 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// | < << > >>

static int spaced_verif(char *readed, int i, int len)
{
	if (!(i > 0 && i < len - 1))
		return (0);

	/* '|' */
		
	if (readed[i] == '|' && readed[i + 1] != ' ')
		return (1);
	if (readed[i] != ' ' && readed[i] != '|' && readed[i - 1] == '|')
		return (1);

	/* '>>' */

	if (i < len - 2 && readed[i] != ' ' && readed[i - 1] == '>' && readed[i - 2] == '>')
		return (1);

	/* '<<' */

	if (i < len - 2 && readed[i] != ' ' && readed[i - 1] == '<' && readed[i - 2] == '<')
		return (1);

	/* '>' */

	if (readed[i] == '>' && readed[i - 1] != ' '&& readed[i - 1] != '>')
		return (1);
	if (readed[i] != ' ' && readed[i] != '>' && readed[i - 1] == '>' && readed[i + 1] != '>')
		return (1);

	/* '<' */

	if (readed[i] == '<' && readed[i - 1] != ' ' && readed[i - 1] != '<')
		return (1);
	if (readed[i] != ' ' && readed[i] != '<' && readed[i - 1] == '<' && readed[i + 1] != '<')
		return (1);
	return (0);
}

static int rebuild_space_len(char *readed, int i)
{
	int j;
	int in_q;

	j = 0;
	in_q = 0;
	while (readed[i])
	{
		if (readed[j] && spaced_verif(readed, i, ft_strlen(readed)))
				((void)0, i++, j++);
		else if (update(readed[i], &in_q))
		{
			i++;
			while (readed[i] && !update(readed[i], &in_q))
				i++;
			i++;
		}
		else
			i++;
	}
	return (i + j);
}

// norm

char *rebuild_space_line(char *readed, int j, int in_q)
{
	int i;
	char *new;

	i = 0;
	new = malloc(sizeof(char) * (rebuild_space_len(readed, 0) + 1));
	while (readed[j])
	{
		if (spaced_verif(readed, j, ft_strlen(readed)))
		{
			new[i++] = ' ';
			new[i++] = readed[j++];
		}
		else if (update(readed[j], &in_q))
		{
			new[i++] = readed[j++];
			while (readed[j] && !update(readed[j], &in_q))
				new[i++] = readed[j++];
			new[i++] = readed[j++];
		}
		else
			new[i++] = readed[j++];
	}
	new[i] = '\0';
	return (new);
}