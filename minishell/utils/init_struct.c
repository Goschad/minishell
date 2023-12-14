/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:56:55 by mbouaza           #+#    #+#             */
/*   Updated: 2023/12/14 13:28:34 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void init_parse(t_shell *shell)
{
	shell->parse = malloc(sizeof(t_parse));
	shell->parse->complete_cmd = NULL;
	shell->parse->split_cmd = NULL;
}

void init_shell(t_shell *shell)
{
	shell->parse = NULL;
	shell->all = NULL;
	shell->cmd = NULL;
	shell->p_cmd = NULL;
	shell->env = NULL;
	shell->mini = 1;
	shell->pipl.n_steps = 0;
	shell->status = 0;
	shell->pipe_nbr = 0;
	shell->and_nbr = 0;
	shell->or_nbr = 0;
	init_parse(shell);
}