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

static void pre(int *i, int *bf, t_shell *sh)
{
    st_cmd(sh, *i, *i + 1);
    *bf  = -1;
    *i = -1;
}

static void redir_v2(int *bf, int *i, t_shell *sh)
{
    if (*bf == REDIR_D_LEFT && sh->p_cmd[*i + 1] && identifie(sh->p_cmd[*i + 1], *bf ) == HEREDOC_PASS)
    {
        redir_left(NULL, sh->p_cmd[*i + 1], REDIR_D_LEFT);
        pre(i, bf, sh);
    }
    else if (*bf == REDIR_LEFT && sh->p_cmd[*i + 1] && identifie(sh->p_cmd[*i + 1], *bf ) == FILE)
    {
        redir_left(sh->p_cmd[*i + 1], NULL, REDIR_LEFT);
        pre(i, bf, sh);
    }
}

void redir(t_shell *sh, int before)
{
    int i;
    char **cpy;

    i = 0;
    cpy = ft_tabdup(sh->p_cmd);
    while (sh->p_cmd[i])
    {
        before = identifie(sh->p_cmd[i], before);
        if (before == REDIR_RIGHT && sh->p_cmd[i + 1] && identifie(sh->p_cmd[i + 1], before) == FILE)
        {
            redir_right(sh->p_cmd[i + 1], REDIR_RIGHT);
            pre(&i, &before, sh);
        }
        else if (before == REDIR_D_RIGHT && sh->p_cmd[i + 1] && identifie(sh->p_cmd[i + 1], before) == FILE)
        {
            redir_right(sh->p_cmd[i + 1], REDIR_D_LEFT);
            pre(&i, &before, sh);
        }
        else
            redir_v2(&before, &i, sh);
        i++;
    }
    tab_free(cpy);
}