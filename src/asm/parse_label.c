/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:06:16 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/23 15:51:07 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"

/*
** - On verifie qu'il y a bien le LABELCHAR
** - On verifie que le lable n'est pas au milieu d'une instruction
** - On verifie que le label contient seulement les LABELSCHAR
** - On verifie que le label n'a pas deja ete donne :
**		si c'est le cas on le stock dans une variable qui nous servira
**		lors du 2eme read, pour saboir qu'il y a un label avant
**		l'instruction et donc le supprimer de la ligne avant de parser
**		l'instruction
** - on ajoute le label dans le maillon
*/

static int	s_label_char(char *line)
{
	int	state_label_char;
	int	i;

	i = -1;
	state_label_char = 0;
	while (line[++i])
	{
		if (line[i] == LABEL_CHAR)
		{
			state_label_char = 1;
			return (i);
		}
	}
	if (state_label_char == 0)
		return (0);
	return (0);
}

void		parse_label(t_instruction **list_instr, t_instruction *cursor,
	char *line)
{
	int	i;

	if ((i = s_label_char(line)) == 0)
		return ;
	else
	{
		if (line[i - 1] == TAB || line[i - 1] == SPACE
		|| line[i - 1] == DIRECT_CHAR || line[i - 1] == SEPARATOR_CHAR)
			return ;
		else
		{
			if (!check_labelschar(line = ft_strtrim(ft_strsub(line, 0, i))))
				return ;
			if (!check_double_label(list_instr, line))
			{
				if (!(cursor->double_label = ft_strnew(ft_strlen(line))))
					return ;
				cursor->double_label = ft_strcpy(cursor->double_label, line);
				return ;
			}
			if (!(cursor->label = ft_strnew(ft_strlen(line))))
				return ;
			cursor->label = ft_strcpy(cursor->label, line);
		}
	}
}
