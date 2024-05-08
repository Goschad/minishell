/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 05:15:54 by mbouaza           #+#    #+#             */
/*   Updated: 2024/05/08 17:26:33 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	is_num_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (FALSE);
	while (str[i])
	{
		if (str[i] > '9' && str[i] < '0')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void	little_export(char *cmd, t_shell *shell)
{
	char	**cpy;
	int		i;

	cpy = NULL;
	i = ft_checkenv(cmd, shell->env);
	if (i >= 0 && format_check(cmd, shell) == 0)
	{
		free(shell->env[i]);
		shell->env[i] = ft_strdup(cmd);
		shell->status = 0;
	}
	else if (i == -1 && format_check(cmd, shell) == 0)
	{
		cpy = ft_tabdup(shell->env);
		tab_free(shell->env);
		shell->env = add_env(cpy, cmd);
		tab_free(cpy);
		shell->status = 0;
	}
}

char	**give_path(char *str)
{
	char	**bash;

	bash = NULL;
	if (!str)
		return (bash);
	bash = ft_split(str, ':');
	return (bash);
}

int	command_exists(char *command, int i)
{
	char	**dir;
	char	*cpy;
	char	*path;
	char	*path_env;

	dir = NULL;
	cpy = NULL;
	path_env = getenv("PATH");
	path = ft_strdup(path_env);
	if (path == NULL)
		return (-1);
	dir = give_path(path);
	if (dir == NULL)
		return (-1);
	free(path);
	while (dir[i] != NULL)
	{
		cpy = ft_join(dir[i++], "/");
		path = ft_join(cpy, command);
		free(cpy);
		if (access(path, F_OK) != FALSE)
			return (free(path), tab_free(dir), TRUE);
		free(path);
	}
	return (tab_free(dir), FALSE);
}

void	incr_shlvl(t_shell *shell)
{
	char	*level;
	char	*shlvl;

	level = NULL;
	shlvl = ft_getenv("SHLVL", shell->env);
	if (is_num_str(shlvl) == FALSE)
	{
		if (shlvl != NULL)
			free(shlvl);
		return (little_export("SHLVL=1", shell));
	}
	level = ft_itoa(ft_atoi(shlvl) + 1);
	free(shlvl);
	shlvl = ft_join("SHLVL=", level);
	little_export(shlvl, shell);
	return (free(shlvl), free(level));
}
