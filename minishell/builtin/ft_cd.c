/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:38:07 by jguerin           #+#    #+#             */
/*   Updated: 2024/03/05 16:23:06 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	cd_home(t_shell *shell)
{
	char	*path_home;

	path_home = ft_getenv("HOME", shell->env);
	if (!path_home)
		put_error("minishell: cd", NULL, 0, "HOME not set");
	else if (chdir(path_home))
		ft_putstr_fd("test", 2);
	return (1);
}

int	ft_cd(char **argv, t_shell *shell)
{
	int	i;
	int	j;
	int	error;

	i = 1;
	j = 0;
	error = 0;
	if (shell->argc == 1)
		cd_home(shell);
	else if (shell->argc > 2)
		put_error("minishell: cd", NULL, 0, "too many arguments");
	else if (argv[i][j] && argv[i][j] == '~')
	{
		shell->path = ft_getenv("HOME", shell->env);
		if (chdir(shell->path) != 0)
			return (free(shell->path), 1);
	}
	else if (argv[i])
	{
		shell->path = ft_strdup(argv[i]);
		error = chdir(shell->path);
		free(shell->path);
		if (error)
			put_error("minishell: cd", argv[i], 0, "No such file or directory");
	}
}
