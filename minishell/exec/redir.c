/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 07:20:13 by marvin            #+#    #+#             */
/*   Updated: 2024/01/03 07:20:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// -bash: test.txt: Permission denied

// check if exist and can access

static permission_set(char *file_name)
{

}

void redir(char *file_name, int v)
{
    int fd;

    fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC)
}