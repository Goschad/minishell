/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:27:32 by mbouaza           #+#    #+#             */
/*   Updated: 2024/05/08 17:25:36 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*actual_path(void)
{
	int		i;
	char	*path;
	char	*actual;

	actual = NULL;
	path = NULL;
	path = getcwd(path, 0);
	i = ft_strlen(path);
	while (i > 0 && path[i] != '/')
		i--;
	actual = ft_substr(path, i + 1, ft_strlen(path) - i);
	free(path);
	path = ft_join(actual, " > ");
	return (free(actual), path);
}
