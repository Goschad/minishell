/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:22:33 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/30 07:33:33 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void remakepp(char **readed)
{
	char *cpy;
	
	cpy = ft_strdup(*readed);
	free(*readed);
	*readed = rebuild_space_line(cpy, 0, 0);
	free(cpy);
}

int banned(char *readed)
{
	int i;

	i = 0;
	if (!ft_strcmp(readed, ""))
		return (-1);
	while (readed[i] && (readed[i] == ' ' || readed[i] == '\t'))
	{
		i++;
		if (!readed[i])
			return (-1);
	}
	return (1);
}

void launch(t_shell *shell)
{
	char *readed;
	char *cpy;
	
	readed = NULL;
	cpy = NULL;
	while (shell->mini == 1)
	{
		// token en debut error
		cpy = actual_path();
		readed = readline(cpy);
		free(cpy);
		cpy = NULL;
		if (readed && banned(readed) == TRUE)
		{
			if (readed && ft_strcmp("", readed))
			 	history(readed);
			remakepp(&readed);
			if (reboot_line(readed) == TRUE && check_quote(readed))
				parse(readed, 0, shell);
		}
		else if (!readed)
			shell->mini = 2;
		free(readed);
	}
}
