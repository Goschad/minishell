/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 07:00:42 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/30 07:28:37 by mbouaza          ###   ########.fr       */
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
    return (HERE);
}

void st_cmd(t_shell *sh, int t1, int t2)
{
    int i;
    int j;
    char **new;

    i = 0;
    j = 0;
    new = malloc(sizeof(char *) * (env_len(sh->p_cmd)));
    if (!new)
        return ;
    while (sh->p_cmd[i] && sh->p_cmd[t1] && sh->p_cmd[t2])
    {
        if (i <= env_len(sh->p_cmd) && i != t1 && i != t2)
            new[j++] = ft_strdup(sh->p_cmd[i++]);
        else
            i++;
    }
    new[j] = NULL;
    tab_free(sh->p_cmd);
    sh->p_cmd = ft_tabdup(new);
    if (new)
        free(new);
}

void redir_left(char *file_name, char *pass, int redir_type)
{
    int fd;

    fd = 0;
    if (pass && redir_type == REDIR_D_LEFT)
    {
        fd = open(".heredoc", O_RDONLY, S_IRWXU | S_IRWXG | S_IRWXO);
        if (fd <= 0)
            return ;
        dup2(fd, STDIN_FILENO);
        close(fd);
    }
    else if (file_name && redir_type == REDIR_LEFT)
    {
        fd = open(file_name, O_RDONLY, S_IRWXU | S_IRWXG | S_IRWXO);
        if (fd <= 0)
            return ;
        dup2(fd, STDIN_FILENO);
        close(fd);
    }
}

void redir_right(char *file_name, int redir_type)
{
    int fd;

    fd = 0;
    if (file_test(file_name) != HERE)
        return ;
    else
    {
        if (redir_type == REDIR_RIGHT)
            fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0777);
        else
            fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0777);
        if (fd < 0)
            return;
        if (dup2(fd, STDOUT_FILENO) < 0)
        {
            close(fd);
            return ;
        }
    }
    close(fd);
}