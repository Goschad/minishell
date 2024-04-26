/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:34:39 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/26 08:45:42 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int quoted_size(char *line)
{
	int i;
	int in_q;
	int len;

	i = -1;
	len = 0;
	in_q = 0;
	while (line[++i])
	{
		if (!update(line[i], &in_q))
			len++;
		i++;
	}
	return (len);
}

int update_sd(char c, int *in_q, int *qs, int *qd)
{
	if (c == '\'' && *in_q != 2)
	{
		*in_q = 1 - (1 * (*in_q == 1));
		*qs += 1;
		return (1);
	}
	else if (c == '\"' && *in_q != 1)
	{
		*in_q = 2 - (2 * (*in_q == 2));
		*qd += 1;
		return (1);
	}
	return (0);
}

int	update(char c, int *in_q)
{
	if (c == '\'' && *in_q != 2)
	{
		*in_q = 1 - (1 * (*in_q == 1));
		return (1);
	}
	if (c == '\"' && *in_q != 1)
	{
		*in_q = 2 - (2 * (*in_q == 2));
		return (1);
	}
	return (0);
}

int	check_quote(char *s)
{
	int	in_q;
	int	count_s;
	int	count_d;
	int	i;

	i = -1;
	in_q = 0;
	count_d = 0;
	count_s = 0;
	while (s[++i])
		update_sd(s[i], &in_q, &count_s, &count_d);
	if (count_d % 2 != 0 || count_s % 2 != 0)
		return (ft_putstr_fd("quote error\n", 2), 0); // mix remake line and other (optional)
	return (1);
}

char *quoted_line(char *line)
{
	char *new;
	int in_q;
	int i;
	int j;

	((void)0, i = quoted_size(line), j = 0, new = NULL, in_q = 0);
	new = malloc(sizeof(char) * (i + 1));
	i = 0;
	if (!new || !line)
		return (NULL);
	while (line[i])
	{
		if (!update(line[i], &in_q))
			new[j++] = line[i];
		i++;
	}
	new[j] = '\0';
	return (new);
}