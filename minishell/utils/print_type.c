/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:56:52 by mbouaza           #+#    #+#             */
/*   Updated: 2024/05/08 17:25:58 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar_fd(str[i++], fd);
}

void	ft_error(char *s1, char *s2, char *s3)
{
	int	i;

	i = 0;
	while (s1 && s1[i])
		ft_putchar_fd(s1[i++], 2);
	i = 0;
	while (s2 && s2[i])
		ft_putchar_fd(s2[i++], 2);
	i = 0;
	while (s3 && s3[i])
		ft_putchar_fd(s3[i++], 2);
}

void	put_error(char *exe, char *file, int err, char *error)
{
	if (!error)
		ft_putstr_fd("minishell: ", 2);
	if (exe)
		ft_error(exe, ": ", NULL);
	if (file)
		ft_error(file, ": ", NULL);
	if (error)
		ft_putstr_fd(error, 2);
	else
		ft_putstr_fd(strerror(err), 2);
	ft_putstr_fd("\n", 2);
}
