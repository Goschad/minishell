/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:26:51 by jguerin           #+#    #+#             */
/*   Updated: 2024/04/26 03:59:02 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	char_cmp(char *str, char *reject)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (reject[j])
		{
			if (str[i] == reject[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	format_check(char *arg, t_shell *shell)
{
	int	current;
	int	flag;

	current = 0;
	flag = 0;
	while (arg[current] && arg[current] != '=')
	{
		if (!ft_isalpha(arg[current]) || is_d(arg[current]))
			flag = 1;
		current++;
	}
	if (flag == 0 && char_cmp(arg, "=") == 1)
		return (0);
	else if (flag == 1)
		return (1);
	return (0);
}

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
