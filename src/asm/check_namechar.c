/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_namechar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:29:50 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/14 10:40:44 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "op.h"
#include "asm.h"


bool 	error_namechar()
{
	ft_putstr_fd("Error : wrong character\n", 1);
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
