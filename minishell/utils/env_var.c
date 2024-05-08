/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:53:47 by mbouaza           #+#    #+#             */
/*   Updated: 2024/05/08 17:14:48 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	check_var(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	check2(char *s, char **env, int i, int j)
{
	char	*str;
	char	*var;

	var = NULL;
	str = NULL;
	var = ft_substr(s, i + 1, j);
	if (s[i + 1] && s[i + 1] == '?')
		return (free(var), TRUE);
	else
	{
		str = ft_getenv(var, env);
		if (str && check_var(str) == TRUE)
			return (multfree(var, str, NULL, NULL), TRUE);
		else
			return (multfree(var, str, NULL, NULL), NO);
	}
}

static int	check(char *s, char **env, int i, int j)
{
	while (s[i])
	{
		if (s[i] == '$' && check_env(s, env, i) == 0 && s[i + 1]
			&& s[i + 1] != '?' && var_c(s, i) == 0)
			return (NO);
		else if (s[i] == '$' && (check_env(s, env, i) == 1 || s[i + 1] == '?')
			&& var_c(s, i) == 0)
		{
			while (s[j + i + 1] && simp_char(s[j + i + 1], " $\'=\"") == 0)
				j++;
			return (check2(s, env, i, j));
		}
		i++;
	}
	return (TRUE);
}

int	id_n_co(t_shell *sh, int *bf, int i)
{
	int	bff;
	int	j;

	j = i;
	bff = *bf;
	*bf = identifie(sh->p_cmd[i], *bf);
	if (env_len(sh->p_cmd) == env_len(sh->n_c_cmd))
		return (TRUE);
	while (sh->n_c_cmd[i])
	{
		bff = identifie(sh->n_c_cmd[i], bff);
		if (bff == FILE && check(sh->n_c_cmd[i], sh->env, 0, 0) == NO)
		{
			if (j == i - 1)
			{
				ft_error("minishell: ", sh->n_c_cmd[i], AMBIG_ERR);
				return (FALSE);
			}
		}
		i++;
	}
	return (TRUE);
}
