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

static int file_test(char *file_name)
{
    int mod;

    mod = access(file_name, F_OK);
    if (mod == -1)
        return (HERE);
    else if (is_dir(file_name) == TRUE)
    {
        ft_putstr_fd("minishell: ", 2);
        ft_putstr_fd(file_name, 2);
        if (file_name[ft_strlen(file_name) - 1] == '/')
            ft_putstr_fd(": Is a directory\n", 2);
        else
            ft_putstr_fd("/: Is a directory\n", 2);
        return (DIRECTORY);
    }
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

void redir_right(char *file_name, int redir_type)
{
    int fd;

    fd = 0;
    if (file_test(file_name) == HERE)
    {
        fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC);
        if (fd <= 0)
            return ;
        dup2(fd, STDOUT_FILENO);
        close(fd);
    }
    else if (file_test(file_name) <= PERM) // file exist but have inssufisance perm
        return ;
    else
    {
        if (redir_type == 0)
            fd = open(file_name, O_WRONLY | O_TRUNC); // clear file to write in it
        else
            fd = open(file_name, O_WRONLY | O_APPEND); // add writing
        if (fd <= 0)
            return ;
        dup2(fd, STDOUT_FILENO);
        close(fd);
    }
}

void redir_left(char *file_name, char *pass, int redir_type)
{
    int fd;

    fd = 0;
    if (pass && redir_type == REDIR_D_LEFT)
    {
        heredoc(pass);
        fd = open(".heredoc", O_RDONLY, S_IRWXU | S_IRWXG | S_IRWXO);
        if (fd <= 0)
            return ;
        dup2(fd, STDIN_FILENO);
        close(fd);
    }
    else if (redir_type == REDIR_LEFT)
    {
        fd = open(file_name, O_RDONLY, S_IRWXU | S_IRWXG | S_IRWXO);
        if (fd <= 0)
            return ;
        dup2(fd, STDIN_FILENO);
        close(fd);
    }
}

/*
void redir(t_shell *sh, int l)
{
    int i;
    int before;

    i = 0;
    before = -1;
    while (sh->)
}
*/

/*

        waitpid(p.pid[p.ti.b], &p.ti.c, WIFEXITED(p.pid[p.ti.b]));
		p.ti.b++;
		g_ms.stat = WEXITSTATUS(p.ti.c);
        
*/