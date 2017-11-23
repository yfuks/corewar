/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:13:19 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/23 14:08:31 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>

static bool	error_instruction(int i)
{
	if (i == 1)
		ft_putstr_fd("Error : wrong mnemonique\n", 2);
	if (i == 2)
		ft_putstr_fd("Error : wrong arguments\n", 2);
	return (false);
}

/*
** - On commence par supprimer le label du debut de la ligne
** - On cherche ensuite le nom de l'instruction (mnemonique)
** - On parse les arguments de l'instruction
*/

bool		parse_instruction(t_instruction *cursor, char *line)
{
	if (!(ft_strcmp((line = ft_strtrim(line)), "")))
		return (true);
	if (cursor->label != NULL)
	{
		line = ft_strtrim(ft_strsub(line, ft_strlen(cursor->label) + 1,
		ft_strlen(line)));
		if (ft_strcmp(line, "") == 0)
		{
			cursor->instr_byte_size = 0;
			return (true);
		}
	}
	if (cursor->double_label != NULL)
		line = ft_strtrim(ft_strsub(line, ft_strlen(cursor->double_label) + 1,
		ft_strlen(line)));
	if (!parse_mnemonique(&cursor, &line))
		return (error_instruction(1));
	if (!parse_arguments(&cursor, line))
		return (false);
	return (true);
}
