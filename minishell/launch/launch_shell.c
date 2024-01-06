/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:22:33 by mbouaza           #+#    #+#             */
/*   Updated: 2024/01/06 10:23:25 by marvin           ###   ########.fr       */
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

static void remake(char **readed, char *(*f)(char *))
{
	char *cpy;
	
	cpy = ft_strdup(*readed);
	free(*readed);
	*readed = f(cpy);
	free(cpy);
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
		readed = readline("minishell > ");
		remake(&readed, &reboot_line);
		if (readed && ft_strcmp("", readed))
			history(readed);
		remakepp(&readed);
		printf("%s\n", readed);
		if (check_quote(readed))
			parse(readed, shell);
		free(readed);
	}
	clear_history();
}