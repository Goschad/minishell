/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_cmd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:53:11 by GIGI              #+#    #+#             */
/*   Updated: 2023/11/14 03:07:49 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int quotes_cmd_size(char *line)
{
    int i;
    int num;
    int in_q;

    i = 0;
    num = 0;
    in_q = 0;
    while (line[i])
    {
        if (update(line[i], &in_q))
        {
            i++;
            num++;
            while (line[i] && !update(line[i], &in_q))
                i++;
            
            i++;
        }
        else
            i++;
    }
    return (num);
}