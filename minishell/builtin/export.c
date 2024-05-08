/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:26:51 by jguerin           #+#    #+#             */
/*   Updated: 2024/05/08 15:07:22 by jguerin          ###   ########.fr       */
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

void	modify_env(char *cmd, t_shell *shell)
{
	int	i;

	i = 0;
	free(shell->env[i]);
	shell->env[i] = ft_strdup(cmd);
	shell->status = 0;
}

void cpy_env(char *cmd, t_shell *shell)
{
	char	**cpy;

	cpy = ft_tabdup(shell->env);
	tab_free(shell->env);
	shell->env = add_env(cpy, cmd);
	tab_free(cpy);
	shell->status = 0;
}

void	ft_export(char **cmd, char **argv, t_shell *shell)
{
	char	**cpy;
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 1;
	flag = 0;
	if (shell->argc == 1)
		return (sort_env(argv, env_len(argv)));
	while (cmd[j])
	{
		i = ft_checkenv(cmd[j], shell->env);
		if (i >= 0 && format_check(cmd[j], shell) == 0)
		{
			free(shell->env[i]);
			shell->env[i] = ft_strdup(cmd[j]);
			shell->status = 0;
		}
		else if (i == -1 && format_check(cmd[j], shell) == 0)
		{
			cpy = ft_tabdup(shell->env);
			tab_free(shell->env);
			shell->env = add_env(cpy, cmd[j]);
			tab_free(cpy);
			shell->status = 0;
		}
		else if (format_check(cmd[j], shell) == 1)
			flag = 1;
		j++;
	}
	if (flag == 1)
	{
		shell->status = 1;
		printf("Minishell : invalid identifier\n");
	}
}

/*	1er if : var d'env existe et aucune erreur de format
	else if : var d'env n'existe pas et aucune erreur de format
	2eme else if : erreur de format*/
