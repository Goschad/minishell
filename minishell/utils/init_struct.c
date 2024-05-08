/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:56:55 by mbouaza           #+#    #+#             */
/*   Updated: 2024/05/08 12:55:14 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void init_shell(t_shell *shell)
{
	shell->all = NULL;
	shell->cmd = NULL;
	shell->heredoc = NULL;
	shell->p_cmd = NULL;
	shell->n_c_cmd = NULL;
	shell->env = NULL;
	shell->forked_cmd = 0;
	shell->mini = 1;
	shell->argc = 0;
	shell->pipl.n_steps = 0;
	shell->status = 0;
	shell->redir = 0;
}
