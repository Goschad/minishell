/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:56:55 by mbouaza           #+#    #+#             */
/*   Updated: 2023/12/21 16:17:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void init_shell(t_shell *shell)
{
	shell->all = NULL;
	shell->cmd = NULL;
	shell->p_cmd = NULL;
	shell->env = NULL;
	shell->mini = 1;
	shell->pipl.n_steps = 0;
	shell->status = 0;
}