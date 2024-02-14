/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 05:54:39 by mbouaza           #+#    #+#             */
/*   Updated: 2023/11/11 01:53:25 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
static int size_of_dir(void)
{	
	int i;
	DIR *directory;
	struct dirent *entry;

	i = 0;
	directory = opendir(".");
	if (directory == NULL)
		return (0);
	while (1)
	{
		entry = readdir(directory);
		if (entry == NULL)
			break;
		i++;
	}
	closedir(directory);
	return (i);
}

static char **get_dir(void)
{
	struct dirent *entry;
	DIR *directory;
	char **ls;
	int i;

	i = size_of_dir();
	if (i == 0)
		return (NULL);
	ls = malloc(sizeof(char *) * (i + 1));
	if (!ls)
		return (NULL);
	i = 0;
	directory = opendir(".");
	while (i < size_of_dir())
	{
        entry = readdir(directory);
		ls[i++] = ft_strdup(entry->d_name);
    }
	ls[i] = NULL;
    closedir(directory);
	return (ls);
}

char *wildcard(char *readed) // 
{
	char **dir;

	dir = get_dir();
	if (dir == NULL)
		return (readed);
	// remplace exemple : *.c 
	return (tab_free(dir), readed);
}