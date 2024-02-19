/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:26:51 by jguerin           #+#    #+#             */
/*   Updated: 2024/02/19 16:05:42 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


/*
Return error if :
- arg start with a number
- arg doesnt contain a letter or a number
- arg doesnt contain an equal sign
*/
int	format_check(char *arg)
{
	int current;
	int has_equal;
	
	current = 0;
	has_equal = 0;
	if (!ft_isalpha(arg[0]))
		printf("Pas de lettre :(\n");
	while(arg[current])
	{
		if (arg[current] == '=')
			has_equal = 1;
		else if (!ft_isalnum(arg[current]) && arg[current] != '_')
			if (!has_equal)
				printf("")
	}
}

ft_export(char *str, t_shell *shell)
{
	
}
