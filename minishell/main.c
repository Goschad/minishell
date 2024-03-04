/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:57:04 by mbouaza           #+#    #+#             */
/*   Updated: 2024/02/14 14:00:21 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int main(int argc, char **argv, char **env)
{
	int status;
	t_shell *shell;

	status = 0;
	shell = malloc(sizeof(t_shell));
	if (!shell)
		return (ft_putstr_fd("Malloc error\n", 2), 0);
	else if (!basic(argc, env, shell))
		return (0);
	make_history(shell);
	launch(shell);
	status = shell->status;
	global_free(shell);
	printf("EOF\n");
	exit(status);
}
