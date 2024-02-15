/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:38:07 by jguerin           #+#    #+#             */
/*   Updated: 2024/02/15 10:14:22 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


int	ft_cd(char **argv, t_shell *shell)
{
	int i = 1;
	int j = 0;
	int error;
	char *path;

	if(shell->argc == 1)
		return (1);
	else if (shell->argc > 2)
	{
		ft_putstr_fd(argv[i], 2);
		ft_putstr_fd(": Too many arguments\n", 2);
		return (1);
	}
	if (argv[i][j] == '~')
	{
		path = ft_getenv("HOME", shell->env);
		if (chdir(path) != 0)
			ft_putstr_fd("No such file or directory v2\n", 2);
	}
	else if (argv[i])
	{
		path = argv[i];
		error = chdir(path);
		if (error)
		{
			ft_putstr_fd(argv[i], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			return(1);
		}
	}
}
