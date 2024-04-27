/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:17:53 by jguerin           #+#    #+#             */
/*   Updated: 2024/04/27 08:45:51 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	pwd(t_shell *shell)
{
	char	*path;

	path = NULL;
	path = getcwd(path, 0);
	printf("%s\n", path);
	free(path);
	return (set_status(0, shell));
}
