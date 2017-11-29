/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:13:19 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/29 18:39:04 by jthillar         ###   ########.fr       */
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
	// ft_putstr_fd("parse instruction: ",1);
	// ft_putstr_fd(line,1);
	// ft_putstr_fd("\n",1);
	if (!(ft_strcmp(line, "")) || !(ft_strcmp((line = ft_trim(line)), "")))
	{
		cursor->instr_byte_size = 0;
		return (true);
	}
	if (cursor->label != NULL)
	{
		line = ft_trim(ft_strsub2(line, ft_strlen(cursor->label) + 1,
		ft_strlen(line)));
		if (ft_strcmp(line, "") == 0)
		{
			cursor->instr_byte_size = 0;
			return (true);
		}
	}
	// ft_putstr_fd("parse instruction2: ",1);
	// ft_putstr_fd(line,1);
	// ft_putstr_fd("\n",1);
	if (cursor->double_label != NULL)
		line = ft_trim(ft_strsub2(line, ft_strlen(cursor->double_label) + 1,
		ft_strlen(line)));
	// ft_putstr_fd("parse instruction3: ",1);
	// ft_putstr_fd(line,1);
	// ft_putstr_fd("\n",1);
	if (!parse_mnemonique(&cursor, line))
		return (error_instruction(cursor));
	// ft_putstr_fd("parse instruction4: ",1);
	// ft_putstr_fd(line,1);
	// ft_putstr_fd("\n",1);
	if (!parse_arguments(&cursor, line))
		return (false);
	// ft_putstr_fd("salut", 1);
	// ft_putstr_fd("\n", 1);
	return (true);
}
