/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:42:54 by mbouaza           #+#    #+#             */
/*   Updated: 2024/03/05 12:54:56 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void ctrl_c(void)
{

}

static __sighandler_t ctrl_backslash(void)
{

}

void build_signal(void)
{
	signal(SIGQUIT, ctrl_backslash()); // signal -> '^\'
    // signal(^C) // signal -> '^C'
	rl_catch_signals = 0;
}