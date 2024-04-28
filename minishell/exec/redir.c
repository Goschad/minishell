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
    return (HERE);
}

// redir_type = version '>' = 0 or '>>' = 1

void redir_right(char *file_name, int redir_type)
{
    int fd;

    fd = 0;
    /*if (file_test(file_name) == HERE)
    {
        fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0777);
        if (fd <= 0)
            return ;
        dup2(fd, STDOUT_FILENO);
        close(fd);
    }*/
    if (file_test(file_name) != HERE)
        return ;
    else
    {
        if (redir_type == 0)
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

static void st_cmd(t_shell *sh, int t1, int t2)
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

        heredoc(pass);
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
/*
prioriter << => > 

<< pass = .herdoc

*/

/*
static int identifie(char *token, int before)
{
    if (!ft_strcmp(token, "<<"))
        return (REDIR_D_LEFT);
    else if (!ft_strcmp(token, ">>"))
        return (REDIR_D_RIGHT);
    else if (!ft_strcmp(token, ">"))
        return (REDIR_RIGHT);
    else if (!ft_strcmp(token, "<"))
        return (REDIR_LEFT);
    else if (before == REDIR_D_LEFT)
        return (HEREDOC_PASS);
    else if (before == REDIR_D_RIGHT || before == REDIR_RIGHT)
        return (FILE);
    else
        return (UNKNOWN);
}
*/

// > et >> c bon  => echo > lol X

void redir(t_shell *sh)
{
    int i;
    int before;
    char **cpy;

    i = 0;
    before = -1;
    cpy = ft_tabdup(sh->p_cmd);
    while (sh->p_cmd[i])
    {
        before = identifie(sh->p_cmd[i], before);
        if (before == REDIR_RIGHT && sh->p_cmd[i + 1] && identifie(sh->p_cmd[i + 1], before) == FILE)
        {
            redir_right(sh->p_cmd[i + 1], 0);
            st_cmd(sh, i, i + 1);
            i = -1;
            before = -1;
        }
        else if (before == REDIR_D_RIGHT && sh->p_cmd[i + 1] && identifie(sh->p_cmd[i + 1], before) == FILE)
        {
            redir_right(sh->p_cmd[i + 1], 1);
            st_cmd(sh, i, i + 1);
            i = -1;
            before = -1;
        }
        else if (before == REDIR_D_LEFT && sh->p_cmd[i + 1] && identifie(sh->p_cmd[i + 1], before) == HEREDOC_PASS)
        {
            redir_left(NULL, sh->p_cmd[i + 1], REDIR_D_LEFT);
            st_cmd(sh, i, i + 1);
            i = -1;
            before = -1;
        }
        i++;
    }
}