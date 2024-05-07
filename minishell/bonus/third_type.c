/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 08:16:58 by mbouaza           #+#    #+#             */
/*   Updated: 2024/03/17 09:56:23 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int have_word(char *str, char *cmp)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i] && cmp[j])
    {
        if (str[i] == cmp[j])
            j++;
        else
            return (FALSE);
        if (cmp[j] == '*' && !cmp[j + 1])
            return (TRUE);
        i++;
    }
    return (FALSE);
}

static int count_files(char **dir, char *line, int x)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (dir[i])
    {
        if (have_word(dir[i], line) == TRUE && dir[i][0] != '.')
            j++;
        i++;
    }
    return (j);
}

static char **set_file(char *line, char **dir)
{
    char **files_list;
    char **dir_in_dir;
    int i;
    int j;

    ((void)0, i = count_files(dir, line, 0), j = 0, files_list = NULL);
    if (i == 0)
        return (NULL);
    files_list = malloc(sizeof(char *) * (i + 1));
    if (!files_list)
        return (NULL);
    i = 0;
    while (dir[i])
    {
        if (have_word(dir[i], line) == TRUE && dir[i][0] != '.')
            files_list[j++] = ft_strdup(dir[i]);
        i++;
    }
    files_list[j] = NULL;
    return (files_list);
}

char *third_type(char *line, char **dir)
{
    char **all;
    char *str;
    int i;

    i = 0;
    str = NULL;
    all = set_file(line, dir);
    if (all == NULL)
        return (ft_strdup(line));
    str = make_it_one(all);
    tab_free(all);
    return (str);
}