/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:47:18 by mbouaza           #+#    #+#             */
/*   Updated: 2023/12/10 04:37:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void shell_execve(char *e_cmd, char **env, t_shell *shell)
{
	int i;
	char *str;
	char *cpy;
	char **bash;

	i = 0;
	cpy = NULL;
	shell->p_cmd = cut_cmd(e_cmd);
	str = ft_getenv("PATH", shell->env);
	bash = ft_split(str, ':');
	free(str);
	while (bash[i]) // /bin/bash
	{
		str = ft_join(bash[i++], "/");
		cpy = ft_join(str, shell->p_cmd[0]); // a changer
		free(str);
		execve(cpy, shell->p_cmd, env);
		free(cpy);
	}
	tab_free(bash);
	printf("minishell: %s: command not found\n", shell->p_cmd[0]);
	set_status(127, shell);
	exit(0);
}