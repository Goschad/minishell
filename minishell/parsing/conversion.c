/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:34:36 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/23 04:46:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void despair(char **s1, char **s2, int *i)
{
	*i = -1;
	if (*s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (*s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return ;
}

static int	char_ccmp(char c, char *reject)
{
	int	j;

	j = 0;
	while (reject[j])
	{
		if (c == reject[j])
			return (1);
		j++;
	}
	return (0);
}

static int	ft_while(char *s, int i)
{
	int	j;

	j = 0;
	if (s[i + j] == '$')
		j++;
	while (s[i + j] && char_ccmp(s[i + j], " =$\"\'") == 0)
		j++;
	if (j > 0)
		j--;
	return (j);
}

static char	*remplace_part(char *s, char *remplace, int start, int end)
{
	int		i;
	int		j;
	int		x;
	char	*new_str;

	i = ft_strlen(remplace);
	x = 0;
	new_str = NULL;
	new_str = malloc(sizeof(char) * (ft_strlen(s) - (end - start)) + i + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < start)
	{
		new_str[i] = s[i];
		i++;
	}
	j = i + end + 1;
	while (i < start + (int) ft_strlen(remplace))
		new_str[i++] = remplace[x++];
	while (s[j])
		new_str[i++] = s[j++];
	new_str[i] = '\0';
	free(s);
	return (new_str);
}

// convertie les var env en leur valeur exemple : $PATH -> env var PATH //

char	*env_conversion(char *s, char **env, int i, t_shell *mini)
{
	int		j;
	char	*var;
	char	*genv;

	((void)0, var = NULL, genv = NULL, j = 0);
	while (s[++i])
	{
		if (s[i] == '$' && check_env(s, env, i) == 0 && s[i + 1] != '?'
			&& var_c(s, i) == 0)
			s = remplace_part(s, " ", i, ft_while(s, i));
		else if (s[i] == '$' && (check_env(s, env, i) == 1
				|| s[i + 1] == '?') && var_c(s, i) == 0)
		{
			while (s[j + i + 1] && simp_char(s[j + i + 1], " $\'=\"") == 0)
				j++;
			var = ft_substr(s, i + 1, j);
			if (s[i + 1] == '?')
				genv = ft_itoa(mini->status);
			else
				genv = ft_getenv(var, env);
			s = remplace_part(s, genv, i, j);
			despair(&genv, &var, &i);
		}
	}
	return (s);
}