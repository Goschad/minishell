/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:50:38 by jguerin           #+#    #+#             */
/*   Updated: 2024/04/26 06:21:16 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	env(char **env, char **cmd, t_shell *shell)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (cmd[j])
	{
		if (ft_strcmp(cmd[j], "env") != 0)
		{
			ft_putstr_fd("No such file or directory\n", 2);
			return (set_status(127, shell));
		}
		j++;
	}
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (set_status(0, shell));
}
