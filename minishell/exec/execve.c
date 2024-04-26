/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:47:18 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/26 11:21:35 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// env -i = var env
#include "../include/minishell.h"

static void	error_msg(char *str)
{
	ft_putstr_fd("Command '", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("' is available in the following places\n", 2);
	ft_putstr_fd("* /bin/", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("* /usr/bin/", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("The command could not be located because", 2);
	ft_putstr_fd(" '/bin:/usr/bin' ", 2);
	ft_putstr_fd("is not included in the PATH environment variable.\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
}

static int	path_is_built_different(char *str, t_shell *shell)
{
	char	*var;

	var = ft_getenv("PATH", shell->env);
	if (!var)
		return (TRUE);
	free(var);
	if (command_exists(str, 0) == FALSE)
	{
		ft_putstr_fd(str, 2);
		return (ft_putstr_fd(": command not found\n", 2), FALSE);
	}
	else if (command_exists(str, 0) == TRUE)
		error_msg(str);
	return (FALSE);
}

static int	unknow_path(t_shell *shell, char **env)
{
	int		stat;
	char	*str;

	stat = 1;
	str = ft_getenv("PATH", shell->env);
	if (!str)
		stat = UNKNOWN;
	else
		free(str);
	if (!ft_strcmp("./minishell", shell->p_cmd[0]) || !ft_strcmp("minishell",
			shell->p_cmd[0]))
	{
		incr_shlvl(shell);
	}
	execve(shell->p_cmd[0], shell->p_cmd, env);
	return (stat);
}

// /bin/ls + shlvl + cat + ctrl c

void	shell_execve(char **env, t_shell *shell)
{
	int		i;
	char	*str;
	char	*cpy;
	char	**bash;

	((void)0, i = 0, cpy = NULL, str = ft_getenv("PATH", shell->env));
	((void)0, str = ft_getenv("PATH", shell->env), bash = give_path(str));
	free(str);
	while (bash && bash[i])
	{
		str = ft_join(bash[i++], "/");
		cpy = ft_join(str, shell->p_cmd[0]); // a changer
		free(str);
		execve(cpy, shell->p_cmd, env);
		free(cpy);
	}
	tab_free(bash);
	if (unknow_path(shell, env) == UNKNOWN)
		printf("minishell: %s: No such file directory\n", shell->p_cmd[0]);
	else if (path_is_built_different(shell->p_cmd[0], shell) == FALSE)
		;
	else
		printf("minishelll: %s: command not found\n", shell->p_cmd[0]);
	set_status(127, shell);
	exit(127);
}
