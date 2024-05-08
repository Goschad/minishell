/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:47:08 by jguerin           #+#    #+#             */
/*   Updated: 2024/05/08 16:06:56 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// update marwen

void	print_exit(void)
{
	ft_putstr_fd("exit\nminishell: exit: ", 2);
}

void	exit_value(int n, char *str, t_shell *shell)
{
	if (n == 1 || (n == 3 && ft_strlen(str) > 21))
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		shell->mini = 0;
		shell->status = 2;
	}
	else if (n == 2)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": too many arguments\n", 2);
		shell->status = 1;
	}
	else if (n == 3)
	{
		ft_putstr_fd("exit\n", 1);
		shell->mini = 0;
		shell->status = ft_atoi(str);
	}
	else if (n == 4)
	{
		ft_putstr_fd("exit\n", 1);
		shell->mini = 0;
	}
}

int	ex(int n, int *test, char *str, t_shell *shell)
{
	if (n == 1)
	{
		print_exit();
		exit_value(1, str, shell);
	}
	else if (n == 2)
	{
		print_exit();
		exit_value(2, str, shell);
	}
	else if (n == 3)
	{
		print_exit();
		exit_value(3, str, shell);
		*test = 0;
	}
	else if (n == 4)
	{
		exit_value(4, str, shell);
	}
	return (1);
}

void	ft_exit(char **av, t_shell *shell, t_exit xt)
{
	xt.i = 1;
	xt.k = 1;
	while (av[xt.i] && shell->argc >= 2)
	{
		xt.j = 0;
		while (av[xt.i][xt.j])
		{
			if (str_is_num(av[xt.i]) == 0)
			{
				xt.j = ft_atoi(av[xt.i]) * -1;
				is_neg(xt.j, shell);
				return ;
			}
			if ((!is_d(av[xt.i][xt.j]) && ex(1, &xt.k, av[xt.i], shell) == 1) ||
				(shell->argc > 2 && ex(2, &xt.k, av[xt.i], shell) == 1))
				return ;
			else if (is_d(av[xt.i][xt.j]) && ex(3, &xt.k, av[xt.i], shell) == 1)
				return ;
			xt.j++;
		}
		xt.i++;
	}
	if (shell->argc == 1 && ex(4, &xt.k, av[xt.i], shell) == 1)
		return ;
}
