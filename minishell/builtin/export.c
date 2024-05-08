/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:26:51 by jguerin           #+#    #+#             */
/*   Updated: 2024/05/08 17:04:26 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	env_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**add_env(char **env, char *var)
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
	new[i++] = ft_strdup(var);
	new[i] = NULL;
	return (new);
}

static void pre1(t_shell *sh, char **cmd, int j, int i)
{
	free(sh->env[i]);
	sh->env[i] = ft_strdup(cmd[j]);
	sh->status = 0;
}

static void pre2(t_shell *shell, char **cpy, int j, char **cmd)
{
	tab_free(shell->env);
	shell->env = add_env(cpy, cmd[j]);
	shell->status = 0;
}

void	ft_export(char **cmd, char **argv, t_shell *shell)
{
	char	**cpy;
	int		i;
	int		j;
	int		flag;

	((void)0, i = 0, j = 0, flag = 0);
	if (shell->argc == 1)
		return (sort_env(argv, env_len(argv)));
	while (cmd[++j])
	{
		i = ft_checkenv(cmd[j], shell->env);
		if (i >= 0 && format_check(cmd[j], shell) == 0)
			pre1(shell, cmd, j, i);
		else if (i == -1 && format_check(cmd[j], shell) == 0)
		{
			cpy = ft_tabdup(shell->env);
			pre2(shell, cpy, j, cmd);
			tab_free(cpy);
		}
		else if (format_check(cmd[j], shell) == 1)
			flag = 1;
	}
	if (flag == 1)
		((void)0, shell->status = 1, printf(ID_ERR));
}

/*	1er if : var d'env existe et aucune erreur de format
	else if : var d'env n'existe pas et aucune erreur de format
	2eme else if : erreur de format*/
