/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:42:54 by mbouaza           #+#    #+#             */
/*   Updated: 2024/05/08 17:00:23 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ctrl_c(int plop)
{
	(void) plop;
	if (g_var == 0)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

void	ctrl_backslash(void)
{
}

void	build_signal(void)
{
	signal(SIGQUIT, (void *)ctrl_backslash);
	signal(SIGINT, ctrl_c);
	rl_catch_signals = 0;
}
