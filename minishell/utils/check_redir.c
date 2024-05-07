/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:13:19 by mbouaza           #+#    #+#             */
/*   Updated: 2024/05/07 15:53:30 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int count(char **str)
{
    int j;
    int i;

    j = 0;
    i = 0;
    while (str[j])
    {
        if (ft_strlen(str[j]) >= 3)
        {
            while (str[j][i])
            {
                if (str[j][i] == '>' || str[j][i] == '<')
                {
                    i++;
                    if (i == 3)
                        return (FALSE);
                }
                else
                    break;
            }
            i = 0;
        }
        j++;
    }
    return (TRUE);
}

static int nl_err(char **str, int bf)
{
    int j;

    j = 0;
    while (str[j])
    {
        if (bf >= REDIR_LEFT && bf <= REDIR_D_LEFT && !str[j])
            return (FALSE);
        bf = identifie(str[j], bf);
        j++;
    }
    return (TRUE);
}

int redir_err(char **str)
{
    int i;

    i = 0; 
    if (str[0] && !ft_strcmp(str[0], "|"))
        return (ft_putstr_fd("pipe error\n", 2) ,FALSE);
    else if (count(str) == FALSE)
       return (ft_putstr_fd(TOKEN_ERR_SHORT, 2) ,FALSE);
    else if (nl_err(str, -1) == FALSE)
        return (ft_putstr_fd(TOKEN_NL_ERR, 2) ,FALSE);
    return (TRUE);
}