/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:53:47 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/26 10:30:58 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_getenv(char *str, char **env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		while (str[j] && env[i][j])
		{
			if (str[j] == env[i][j])
			{
				j++;
				if (!str[j] && env[i][j] && env[i][j] == '=')
					return (ft_substr(env[i], j + 1, ft_strlen(env[i])));
			}
			else
				break ;
		}
		i++;
		j = 0;
	}
	return (NULL);
}

int	ft_checkenv(char *str, char **env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		while (str[j] && env[i][j])
		{
			if (str[j] == env[i][j])
			{
				j++;
				if (str[j] && env[i][j] && env[i][j] == '=' && str[j] == '=')
					return (i);
			}
			else
				break ;
		}
		i++;
		j = 0;
	}
	return (-1);
}

int	ft_checkenv2(char *str, char **env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		while (str[j] && env[i][j])
		{
			if (str[j] == env[i][j])
			{
				if (str[j] && env[i][j + 1] && env[i][j + 1] == '=' &&
					str[j + 1] == '\0')
					return (i);
				j++;
			}
			else
				break ;
		}
		i++;
		j = 0;
	}
	return (-1);
}

static void	print_sorted_env(char **tab, int i)
{
	int	j;
	int	flag;

	((void)0, j = -1, flag = 0);
	while (tab[++j])
	{
		write(1, "declare -x ", 12);
		while (tab[j][++i])
		{
			if (tab[j][i] == '=' && flag == 0)
			{
				write(1, "=\"", 2);
				flag = 1;
			}
			else if (tab[j][i + 1] == '\0' && flag == 1)
			{
				write(1, &tab[j][i], 1);
				write(1, "\"\n", 2);
				flag = 0;
			}
			else
				write(1, &tab[j][i], 1);
		}
		i = -1;
	}
}

void	sort_env(char **tab, int env_len)
{
	int		i;
	int		ordered;
	char	*tmp;

	ordered = 0;
	i = 0;
	while (tab[i] && ordered == 0)
	{
		ordered = 1;
		i = -1;
		while (++i < env_len - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = ft_strdup(tab[i]);
				free(tab[i]);
				tab[i] = ft_strdup(tab[i + 1]);
				free(tab[i + 1]);
				tab[i + 1] = ft_strdup(tmp);
				free(tmp);
				ordered = 0;
			}
		}
	}
	print_sorted_env(tab, -1);
}
