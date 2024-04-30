/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:31:05 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/30 07:15:49 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	basic(int argc, char **env, t_shell *shell)
{
	if (argc != 1)
		return (ft_putstr_fd("Argument error\n", 2), -1);
	init_shell(shell);
	shell->argc = argc;
	shell->env = ft_tabdup(env);
	if (!shell->env)
		return (ft_putstr_fd("Env error\n", 2), -1);
	return (1);
}

int	is_d(int n)
{
	if (!(n >= '0' && n <= '9'))
		return (0);
	return (1);
}

int	str_is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[++i] == '\0')
			return (1);
		while (str[i])
		{
			if (!is_d(str[i]))
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}

void	is_neg(int n, t_shell *shell)
{
	shell->status = 0;
	while (n > 0)
	{
		if (shell->status < 0)
		{
			shell->status = 255;
		}
		n--;
		shell->status -= 1;
	}
	shell->mini = 0;
	ft_putstr_fd("exit\n", 1);
	return ;
}
