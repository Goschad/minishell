/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:35:13 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/27 08:14:18 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int rebuild(int fd)
{
	ft_putstr_fd("History file error 🤨 ...\n", 2);
	ft_putstr_fd("re-build history file 😴 ...\n", 1);
	unlink("./history/.shellHistory");
	fd = open("./history/.shellHistory", O_CREAT | O_WRONLY | O_APPEND, 0777);
	ft_putstr_fd("re-builded file 🥳 yeah 🎉\n", 1);
	return (fd);
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

// read gnl

static void update_history(void)
{
	int fd;
	char *line;
	
	line = NULL;
	fd = open("./history/.shellHistory", O_RDONLY);
	if (fd <= 0)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		no_newline(line);
		add_history(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void make_history(t_shell *shell)
{
	int fd;

	fd = 0;
	fd = open("./history/.shellHistory", O_WRONLY | O_APPEND, 0777);
	if (fd < 0)
		fd = rebuild(fd);
	close(fd);
	update_history();
}

void history(char *readed)
{
	int i;
	int fd;
	
	i = 0;
	fd = open("./history/.shellHistory", O_WRONLY | O_APPEND, 0777);
	while (readed[i])
		write(fd, &readed[i++], 1);
	write(fd, "\n", 1);
	add_history(readed);
	close(fd);
}