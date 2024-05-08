/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_check2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:52:02 by jguerin           #+#    #+#             */
/*   Updated: 2024/05/08 17:06:17 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_'))
		return (1);
	return (0);
}
int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

int	format_check(char *arg, t_shell *shell)
{
	int	current;
	int	flag;

	current = 0;
	flag = 0;
	while (arg[current] && arg[current] != '=')
	{
		if (!ft_isalpha(arg[0]) || is_d(arg[0]))
			flag = 1;
		current++;
	}
	if (flag == 0 && char_cmp(arg, "=") == 1)
		return (0);
	else if (flag == 1)
		return (1);
	return (2);
}

int	format_check_unset(char *arg, t_shell *shell)
{
	int	current;
	int	flag;

	current = 0;
	flag = 0;
	while (arg[current] && arg[current] != '=')
	{
		if (!ft_isalpha(arg[current]) || is_d(arg[current]))
			flag = 1;
		current++;
	}
	if (flag == 0 && char_cmp(arg, "=") == 1)
		return (0);
	else if (flag == 1)
		return (1);
}
