/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:13:19 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/30 13:04:43 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


static void err(char *str, int bool)
{
    ft_error(TOKEN_ERR, NULL, NULL);
    ft_putchar_fd(str[0], 2);
    if (bool == TRUE)
        ft_putchar_fd(str[1], 2);
    ft_error("'\n", NULL, NULL);
}

// a faire //

static int token(char **str, int len)
{
    if (ft_strlen(str) >= 1)
    {
        if (str[0] == '<' || str[0] == '|'
            || str[0] == '>' || str[0] == '&')
        {
            if (ft_strlen(str) == 1)
                return (err(str, FALSE), FALSE);
            else
            {
                if (str[1] == '<' || str[1] == '|'
                    || str[1] == '>' || str[1] == '&')
                    return (err(str, FALSE), FALSE);
                else
                    return (err(str, TRUE), FALSE);
            }
        }
    }
    return (TRUE);
}

int redir_err(char *str)
{
    int i;

    i = 0;  
    
    return (TRUE);
}