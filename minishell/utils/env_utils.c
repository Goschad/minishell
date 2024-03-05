/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:53:47 by mbouaza           #+#    #+#             */
/*   Updated: 2024/03/02 12:42:26 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char *ft_getenv(char *str, char **env)
{
	int i;
	int j;

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
				break;
		}
		i++;
		j = 0;
	}
	return (NULL);
}

void	sort_env(char **tab, int env_len)
{
	int		i;
	int		ordered;
	char	*tmp;

	ordered = 0;
	while(tab && ordered == 0)
	{
		ordered = 1;
		i = 0;
		while (i < env_len -1)
		{
			if(ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				ordered = 0;
			}
			printf("%s\n", tmp);
			i++;
		}
		env_len--;
	}
}
