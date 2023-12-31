/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:53:47 by mbouaza           #+#    #+#             */
/*   Updated: 2023/12/22 05:35:04 by marvin           ###   ########.fr       */
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