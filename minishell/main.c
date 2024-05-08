/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:57:04 by mbouaza           #+#    #+#             */
/*   Updated: 2024/05/08 17:27:03 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	int		status;
	t_shell	*shell;

	status = 0;
	shell = malloc(sizeof(t_shell));
	if (!shell)
		return (ft_putstr_fd("Malloc error\n", 2), 0);
	else if (!basic(argc, env, shell))
		return (0);
	build_signal();
	make_history(shell);
	launch(shell);
	status = shell->status;
	global_free(shell);
	exit(status);
}
