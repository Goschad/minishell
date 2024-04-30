/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 04:28:53 by GIGI              #+#    #+#             */
/*   Updated: 2024/04/30 08:08:47 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// test good "pa  rt"e zcaca"popo"'zzzz'

static void make_him_back(char **cmds, char **quoted, int t)
{
    int in_q;
    int i;
    int j;
    int x;

    ((void)0, i = 0, j = 0, in_q = 0, x = 0);

    while (cmds[i] && quoted[t])
    {
        ((void)0, j = 0, in_q = 0);
        while (cmds[i][j])
        {
            x = 0;
            if (update(cmds[i][j], &in_q))
            {
                while (quoted[t] && quoted[t][x] && cmds[i][j])
                    cmds[i][j++] = quoted[t][x++];
                t++;
            }
            j++;
        } 
        i++;
    }
}

static char **sub_quoted_str(char *line, int i, int j)
{
    int s;
    int in_q;
    char **quoted;

    ((void)0, s = 0, in_q = 0, quoted = NULL);
    quoted = malloc(sizeof(char *) * (quotes_cmd_size(line) + 1));
    if (!quoted)
        return (NULL);
    while (line[i])
    {
        if (update(line[i], &in_q))
        {
            j = i;
            i++;
            while (!update(line[i], &in_q))
                i++;
            i++;
            quoted[s++] = ft_substr(line, j, i - j);
        }
        else
            i++;
    }
    quoted[s] = NULL;
    return (quoted);
}

static void fill_line(char *line)
{
    int in_q;
    int i;

    i = 0;
    in_q = 0;
    while (line[i])
    {
        if (update(line[i], &in_q))
        {
            i++;
            while (line[i] && !update(line[i], &in_q))
            {
                if (line[i] == ' ')
				    line[i++] = '0';
                else
                    i++;
            }
            i++;
        }
        else
            i++;
    }
}

char **cut_cmd(char *line)
{
    char **quoted;
    char **cmds;

    quoted = NULL;
    cmds = NULL;
    quoted = sub_quoted_str(line, 0, 0);
    fill_line(line);
    cmds = ft_split(line, ' ');
    make_him_back(cmds, quoted, 0);
    tab_free(quoted);
    return (cmds);
}