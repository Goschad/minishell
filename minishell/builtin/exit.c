/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:47:08 by jguerin           #+#    #+#             */
/*   Updated: 2024/03/15 13:43:45 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_exit(void)
{
	ft_putstr_fd("exit\nminishell: exit: ", 2);
}

void	exit_value(int n, char *str, t_shell *shell)
{
	if (n == 1)
	{
		ft_putstr_fd("numeric argument required\n", 2);
		shell->mini = 0;
		shell->status = 255;
	}
	else if (n == 2)
	{
		ft_putstr_fd("too many arguments\n", 2);
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
	if (n >= 0 && n < 5)
	{
		print_exit();
		exit_value(n, str, shell);
		if (n == 3)
			*test = 0;
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
				return (is_neg(xt.j, shell));
			}
			if (!is_d(av[xt.i][xt.j]) && ex(1, &xt.k, av[xt.i], shell) == 1)
				return ;
			else if (shell->argc > 2 && ex(2, &xt.k, av[xt.i], shell) == 1)
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
