/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 01:38:04 by mbouaza           #+#    #+#             */
/*   Updated: 2023/11/11 01:38:13 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int count_pipe(char *readed)
{
	int pipe_nbr;
	int in_q;
	int i;

	((void)0, i = 0, pipe_nbr = 0, in_q = 0);
	while (readed[i])
	{
		update(readed[i], &in_q);
		if (!in_q && readed[i] == '|')
		{
			if ((readed[i + 1] && readed[i + 1] != '|') || !readed[i + 1])
				pipe_nbr++;
		}
		i++;
	}
	return (pipe_nbr);
}

static int count_or(char *readed) // bonus or
{
	int or_nbr;
	int in_q;
	int i;

	((void)0, i = 0, or_nbr = 0, in_q = 0);
	while (readed[i])
	{
		update(readed[i], &in_q);
		if (!in_q && readed[i] == '|')
		{
			if ((readed[i + 1] && readed[i + 1] == '|'))
				or_nbr++;
		}
		i++;
	}
	return (or_nbr);
}