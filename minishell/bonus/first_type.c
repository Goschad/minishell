/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 06:36:12 by mbouaza           #+#    #+#             */
/*   Updated: 2024/03/17 07:54:23 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int ft_follow_cmp(char *str, char *cmp)
{
	int i;
	int j;

	i = ft_strlen(str);
	j = ft_strlen(cmp);
	while (i >= 0 && j >= 0)
	{
		if (str[i] != cmp[j])
			return (FALSE);
		i--;
		j--;
	}
	if (i < 0 && j >= 0)
		return (FALSE);
	return (TRUE);
}

static int count_files(char **dir, char *line, int x, int a)
{
    int i;
    int j;
    char **s_dir;

    i = 0;
    j = 0;
    while (dir[i])
    {
        if ((ft_follow_cmp(dir[i], line) == 1 || a == 1) && dir[i][0] != '.')
            j++;
        i++;
    }
    return (j);
}

static char **set_file(char *line, char **dir, int a)
{
    char **files_list;
    char **dir_in_dir;
    int i;
    int j;

    ((void)0, i = count_files(dir, line, 0, a), j = 0, files_list = NULL);
    if (count_files == 0)
        return (NULL);
    files_list = malloc(sizeof(char *) * (i + 1));
    if (!files_list)
        return (NULL);
    i = 0;
    while (dir[i])
    {
        if ((ft_follow_cmp(dir[i], line) == 1 || a == 1) && dir[i][0] != '.')
            files_list[j++] = ft_strdup(dir[i]);
        i++;
    }
    files_list[j] = NULL;
    return (files_list);
}

char *first_type(char *line, char **dir, int type)
{
    char **all;
    char *str;
    int i;

    i = 0;
    str = NULL;
    all = set_file(line + 1, dir, type);
    if (all == NULL)
        return (ft_strdup(line));
    str = make_it_one(all);
    tab_free(all);
    return (str);
}