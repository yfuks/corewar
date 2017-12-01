/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_namechar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:29:50 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/15 15:09:51 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "asm.h"

static bool 	error_namechar()
{
	ft_putstr_fd("Error : wrong character\n", 2);
	return (false);
}

bool	check_namechar(char *line, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (line[i] == '\"')
			return (error_namechar());
		i++;
	}
	return (true);
}
