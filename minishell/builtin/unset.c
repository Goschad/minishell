/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:26:59 by jguerin           #+#    #+#             */
/*   Updated: 2024/04/26 03:59:49 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	**ft_add_env(char **env)
{
	int		i;
	char	**new;

	i = 0;
	new = malloc(sizeof(char *) * (env_len(env) + 2));
	while (env[i])
	{
		new[i] = ft_strdup(env[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	ft_unset(char **cmd, char **argv, t_shell *shell)
{
	char	**cpy;
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 1;
	flag = 0;
	if (shell->argc == 1)
		return ;
	while (cmd[j])
	{
		i = ft_checkenv2(cmd[j], shell->env);
		if (i >= 0 && format_check(cmd[j], shell) == 0)
		{
			free(shell->env[i]);
			cpy = ft_tabdup(shell->env);
			shell->env = ft_add_env(cpy);
			tab_free(cpy);
			shell->status = 0;
		}
		j++;
	}
}
