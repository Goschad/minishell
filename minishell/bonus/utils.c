/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 05:54:39 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/26 11:31:00 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	size_of_dir(char *dir)
{
	int				i;
	DIR				*directory;
	struct dirent	*entry;

	i = 0;
	directory = opendir(dir);
	if (directory == NULL)
		return (0);
	while (1)
	{
		entry = readdir(directory);
		if (entry == NULL)
			break ;
		i++;
	}
	closedir(directory);
	return (i);
}

int	is_dir(char *dir)
{
	struct stat	stat_info;

	if (lstat(dir, &stat_info) == 0)
	{
		if (S_ISDIR(stat_info.st_mode))
			return (TRUE);
	}
	return (FALSE);
}

char	**get_dir(char *dir)
{
	struct dirent	*entry;
	DIR				*directory;
	char			**ls;
	int				i;

	i = size_of_dir(dir);
	if (i == 0)
		return (NULL);
	ls = malloc(sizeof(char *) * (i + 1));
	if (!ls)
		return (NULL);
	i = 0;
	directory = opendir(dir);
	while (i < size_of_dir(dir))
	{
		entry = readdir(directory);
		ls[i++] = ft_strdup(entry->d_name);
	}
	ls[i] = NULL;
	closedir(directory);
	return (ls);
}
