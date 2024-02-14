/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:38:07 by jguerin           #+#    #+#             */
/*   Updated: 2024/02/14 12:12:03 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_cd(char **argv, t_shell *shell)
{
	int i = 1;
	int j = 0;
	char *path;

	if(shell->argc == 0)
		printf("ouah chaud");
	else if (shell->argc > 2)
	{
		ft_putstr_fd(argv[i], 2);
		ft_putstr_fd(": Too many arguments\n", 2);
		return (1);
	}
	else if (argv[i][j] == '~')
	{
		path = ft_getenv("HOME", shell->env);
		chdir(path);
	}
}
