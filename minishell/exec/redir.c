/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 07:20:13 by marvin            #+#    #+#             */
/*   Updated: 2024/01/03 07:20:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// bash: test.txt: Permission denied

// check if exist and can access

static int file_test(char *file_name, int flag)
{
    int mod;

    mod = -1;
    if (flag == HERE)
        mod = access(file_name, F_OK);
    else if (flag == PERM)
        mod = access(file_name, F_OK | W_OK);

    if (flag == PERM && mod == -1)
    {
        ft_putstr_fd("minishell: ", 2);
        ft_putstr_fd(file_name, 2);
        ft_putstr_fd(": Permission denie\n", 2);
        return (PERM);
    }
    else if (flag == HERE && mod == -1)
        return (HERE);
    return (1);
}

// pas fini

void redir(char *file_name, int v)
{
    int fd;

    fd = 0;
    if (v == 0 && file_test(file_name, HERE) == 1)
    fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC);
}