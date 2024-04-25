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

// bash: directory_name/: Is a directory -> is_dir

// check if exist and can access

static int file_test(char *file_name)
{
    int mod;

    mod = access(file_name, F_OK);
    if (mod == -1)
        return (HERE);
    mod = access(file_name, F_OK | W_OK);
    if (mod == -1)
    {
        ft_putstr_fd("minishell: ", 2);
        ft_putstr_fd(file_name, 2);
        ft_putstr_fd(": Permission denie\n", 2);
        return (PERM);
    }
    return (1);
}

// redir_type = version '>' = 0 or '>>' = 1

void redir(char *file_name, int redir_type)
{
    int fd;

    fd = 0;
    if (file_test(file_name) == HERE) // file doesn't exist, so i don't care about perm or v
        fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC);
    else if (file_test(file_name) == PERM) // file exist but have inssufisance perm
        return ;
    else
    {
        if (redir_type == 0)
            fd = open(file_name, O_WRONLY | O_TRUNC); // clear file to write in it
        else
            fd = open(file_name, O_WRONLY | O_APPEND); // add writing
    }
    if (fd <= 0)
        return ;
    dup2(fd, 1);
    close(fd);
}