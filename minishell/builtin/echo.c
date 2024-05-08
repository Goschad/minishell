/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:26:55 by jguerin           #+#    #+#             */
/*   Updated: 2024/05/08 16:06:47 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	nb_arg(char **arg)
{
	int	size;

	size = 0;
	while (arg[size])
		size++;
	return (size);
}

int	is_flag_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-')
		return (1);
	else if (str[i] == '-' && str[i + 1] == '\0')
		return (1);
	i++;
	while (str[i] == 'n')
		i++;
	if (str[i] == '\0')
		return (0);
	else
		return (1);
}

void	echo(char **args, t_shell *shell)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	if (nb_arg(args) > 1)
	{
		while (args[i] && is_flag_valid(args[i]) == 0)
		{
			n_flag = 1;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1] && args[1][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (n_flag == 0)
		write(1, "\n", 1);
	return (set_status(0, shell));
}
