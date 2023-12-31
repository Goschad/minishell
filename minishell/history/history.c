/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:35:13 by mbouaza           #+#    #+#             */
/*   Updated: 2023/11/15 23:31:08 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void rebuild(int *fd)
{
	char **rm;

	ft_putstr_fd("History file error 🤨 ...\n", 2);
	ft_putstr_fd("re-build history file 😴 ...\n", 1);
	unlink("./history/.shellHistory");
	close(*fd);
	*fd = open("./history/.shellHistory", O_CREAT | O_RDWR | O_APPEND, 0777);
	ft_putstr_fd("re-builded file 🥳 yeah 🎉\n", 1);
}

static void no_newline(char *readed)
{
	int i;

	i = ft_strlen(readed) - 1;
	while (readed[i] && i > 0)
	{
		if (readed[i] == '\n')
		{
			readed[i] = '\0';
			break;
		}
		i--;
	}	
}

static void update_history(int fd)
{
	char *line;

	line = NULL;
	line = get_next_line(fd);
	while (line)
	{
		no_newline(line);
		add_history(line);
		free(line);
		line = get_next_line(fd);
	}
}

void make_history(t_shell *shell)
{
	int fd;

	if (fd < 0)
		rebuild(&fd);
	update_history(fd);
	close(fd);
}

void history(char *readed)
{
	int fd;
	
	fd = open("./history/.shellHistory", O_WRONLY | O_APPEND);
	ft_putstr_fd(readed, fd);
	ft_putstr_fd("\n", fd);
	add_history(readed);
	close(fd);
}