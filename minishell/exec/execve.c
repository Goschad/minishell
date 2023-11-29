/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:47:18 by mbouaza           #+#    #+#             */
/*   Updated: 2023/11/15 23:21:31 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void shell_execve(t_shell *shell)
{
	int i;
	char *str;
	char *cpy;
	char **bash;

	i = 0;
	cpy = NULL;
	str = ft_getenv("PATH", shell->env);
	bash = ft_split(str, ':');
	free(str);
	while (bash[i]) // /bin/bash
	{
		str = ft_join(bash[i++], "/");
		cpy = ft_join(str, shell->all[0]); // a changer
		free(str);
		execve(cpy, shell->all, shell->env);
		free(cpy);
	}
	tab_free(bash);
	printf("minishell: %s: command not found\n", shell->all[0]);
	set_status(127, shell);
}