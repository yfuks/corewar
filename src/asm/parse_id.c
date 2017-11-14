/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:56:33 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/14 08:32:56 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tools.h"
#include <stdio.h>

bool	parse_id(t_header *header, char *line)
{

	
	header = NULL;

	line = ft_strtrim(line);
	printf("%s\n", line);
/**	while (line++)
	{
		if (*line == '#')
			return (true);
		if (*line == '.' && header->state == 0)
			if
	}**/
	return (true);
}
