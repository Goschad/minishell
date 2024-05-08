/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 04:34:30 by marvin            #+#    #+#             */
/*   Updated: 2024/04/23 04:34:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*change_path(char *argv)
{
	int		i;
	char	*new_argv;

	i = ft_strlen(argv);
	new_argv = malloc(sizeof(char) * i + 2);
	if (!new_argv)
		return (NULL);
	i = 0;
	while (argv[i] && simp_char(argv[i], " \t\n\r\v") == 0)
	{
		new_argv[i] = argv[i];
		i++;
	}
	new_argv[i++] = '=';
	new_argv[i] = '\0';
	return (new_argv);
}

static int	check_path(char *argv, char **env, int n)
{
	int			i;
	int			j;
	char		*copy;

	j = 0;
	if (n == 1)
		copy = change_path(argv);
	else
		copy = ft_strdup(argv);
	if (!copy)
		return (0);
	while (env[j])
	{
		i = 0;
		while (copy[i] == env[j][i])
		{
			if (env[j][i] == '=' && copy[i] == '=')
				return (free(copy), 1);
			i++;
		}
		j++;
	}
	return (free(copy), 0);
}

int	var_c(char *s, int i)
{
	int		in_q;
	int		in_dq;
	int		in_sq;
	int		j;

	in_dq = 0;
	in_sq = 0;
	j = 0;
	while (j < i)
		update_sd(s[j++], &in_q, &in_sq, &in_dq);
	if (in_sq % 2 != 0)
		return (1);
	return (0);
}

int	simp_char(char c, char *reject)
{
	int	i;

	i = 0;
	while (reject[i])
	{
		if (reject[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_env(char *s, char **env, int i)
{
	int		j;
	char	*path;

	j = i;
	path = NULL;
	while (s[j] && simp_char(s[j + 1], " $\'=\"") == 0)
		j++;
	path = ft_substr(s, i + 1, j - i);
	if (!path)
		return (0);
	if (check_path(path, env, 1) == 1)
		return (free(path), 1);
	free(path);
	return (0);
}
