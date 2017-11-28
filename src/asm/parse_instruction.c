/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:13:19 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/28 16:03:47 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>

static bool	error_instruction(t_instruction *cursor)
{
	ft_putstr_fd("line : ", 2);
	ft_putnbr_fd(cursor->nb_line, 2);
	ft_putstr_fd(" -> wrong mnemonique\n", 2);
	return (false);
}

/*
** - On commence par supprimer le label du debut de la ligne
** - On cherche ensuite le nom de l'instruction (mnemonique)
** - On parse les arguments de l'instruction
*/

bool		parse_instruction(t_instruction *cursor, char *line)
{
	char *line2;
	char *line3;
	char *line4;
	if (!(ft_strcmp((line2 = ft_strtrim(line)), "")))
		return (true);
	if (cursor->label) // != NULL)
	{
		line3 = ft_strsub(line2, ft_strlen(cursor->label) + 1, ft_strlen(line2));
		line4 = ft_strtrim(line3);
		if (ft_strcmp(line4, "") == 0)
		{
			cursor->instr_byte_size = 0;
			return (true);
		}
	}
	ft_putstr_fd(line4, 1);
	ft_putstr_fd("\n", 1);
	if (cursor->double_label != NULL)
		line4 = ft_strtrim(ft_strsub(line3, ft_strlen(cursor->double_label) + 1,
		ft_strlen(line3)));
	if (!parse_mnemonique(&cursor, &line4))
		return (error_instruction(cursor));
	if (!parse_arguments(&cursor, line4))
		return (false);
	return (true);
}
