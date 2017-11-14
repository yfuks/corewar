/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:06:16 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/14 12:18:57 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"

void	parse_label(t_instruction **list_instr, char *line)
{
	int state_label_char;
	int i;

	i = -1;
	state_label_char = 0;
	while(line[++i])
	{
		if (line[i] == LABEL_CHAR)
		{
			state_label_char = 1;
			break;
		}
	}
	if (state_label_char == 0)
		return ; // s'il n'y a pas de LABEL_CHAR, on est sur de ne pas avoir de label
	else
	{
		if (line[i - 1] == TAB || line[i - 1] == SPACE
		|| line[i - 1] == DIRECT_CHAR || line[i - 1] == SEPARATOR_CHAR)
			return ; //s'il y a un espace, un tab ou un %, le label fait parti d'argument ou il y a une erreur
		else
			line = ft_strtrim(ft_strsub(line, 0, i));
			if (!check_labelschar(line))
				return;
			add_end_instruction(list_instr);
			if(!((*list_instr)->label = ft_strnew(ft_strlen(line))))
			 	return;
			(*list_instr)->label = ft_strcpy((*list_instr)->label, line);
	}
}
