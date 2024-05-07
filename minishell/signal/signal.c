/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:42:54 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/28 11:27:08 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*static void	ctrl_c(int plop)
{
	(void) plop;
	if (1)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	return ;
}

static __sighandler_t	ctrl_backslash(void)
{
	return (0);
}*/

void	build_signal(void)
{
	/*signal(SIGQUIT, ctrl_backslash());
	signal(SIGINT, ctrl_c);
	rl_catch_signals = 0;*/
}