/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:56:33 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/13 18:26:40 by alansiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tools.h"
#include <stdio.h>

bool	parse_id(t_header *header, char *line)
{
	char	**tab;

	printf("%s\n", line);
	tab = ft_split_t_sp(line, ' ', '\t');
	printf("%s\n", tab[0]);
	printf("%s\n", tab[1]);
	printf("%s\n", tab[2]);
	printf("%s\n", tab[3]);
	printf("%s\n", tab[4]);
	printf("%s", tab[5]);
	header = NULL;
/**	while (line++)
	{
		if (*line == '#')
			return (true);
		if (*line == '.' && header->state == 0)
			if 
	}**/
	return (true);
}
