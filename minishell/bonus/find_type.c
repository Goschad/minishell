/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 06:41:59 by mbouaza           #+#    #+#             */
/*   Updated: 2024/03/17 09:47:07 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int first(char *str)
{
    int i;

    i = 0;
    if (str[0] == '*')
    {
        while (str[i] == '*')
            i++;
        if (str[i] == '\0')
            return (2);
    }
    i = ft_strlen(str);
    if (i > 1 && str[0] == '*')
    {
        i = 1;
        while (str[i])
        {
            if (str[i] == '*')
                return (FALSE);
            i++;
        }
        return (TRUE);
    }
    return (FALSE);
}

int seconde(char *str)
{
    int i;

    i = 1;
    if (ft_strlen(str) >= 3)
    {
        if (str[0] == '*' && str[ft_strlen(str) - 1] == '*')
        {
            while (str[i] && i < ft_strlen(str) - 1)
            {
                if (str[i] == '*')
                    return (FALSE);
                i++;
            }
            return (TRUE);
        }
    }
    return (FALSE);
}

int third(char *str)
{
    int i;

    i = ft_strlen(str) - 1;
    if (str[i] == '*' && i >= 0)
    {
        i--;
        while (i >= 0)
        {
            if (i >= 0 && str[i] == '*')
                return (FALSE);
            i--;
        }
        return (TRUE);
    }
    return (FALSE);
}