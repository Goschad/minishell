/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:58:29 by mbouaza           #+#    #+#             */
/*   Updated: 2024/05/08 17:30:40 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	find_type(char *str)
{
	if (first(str) == TRUE || first(str) == 2)
		return (first(str));
	else if (seconde(str) == TRUE)
		return (3);
	else if (third(str) == TRUE)
		return (4);
	return (-1);
}

static char	*launch_wildcard(char *wild, char **dir, int choice)
{
	char	*str;

	str = NULL;
	if (choice == 1)
		str = first_type(wild, dir, 0);
	else if (choice == 2)
		str = first_type(wild, dir, 1);
	else if (choice == 3)
		str = seconde_type(wild, dir);
	else if (choice == 4)
		str = third_type(wild, dir);
	return (str);
}

char	**wildcard(char **readed)
{
	int		i;
	char	**new;
	char	**dir;
	char	*cpy;

	((void)0, i = 0, new = ft_tabdup(readed), cpy = NULL, dir = get_dir("."));
	if (dir == NULL)
		return (readed);
	while (new[i])
	{
		if (find_type(new[i]) > 0)
		{
			cpy = ft_strdup(new[i]);
			free(new[i]);
			new[i] = launch_wildcard(cpy, dir, find_type(cpy));
			if (!new[i])
				new[i] = ft_strdup(cpy);
			free(cpy);
		}
		i++;
	}
	return (tab_free(dir), new);
}
