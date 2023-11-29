/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:22:33 by mbouaza           #+#    #+#             */
/*   Updated: 2023/11/14 04:48:31 by mbouaza          ###   ########.fr       */
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
		readed = readline("minishell > ");
		remake(&readed, &reboot_line);
		if (readed && ft_strcmp("", readed))
			history(readed);
		remakepp(&readed);
		if (check_quote(readed))
			parse(readed, shell);
		free(readed);
	}
	clear_history();
}