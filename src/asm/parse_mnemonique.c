/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mnemonique.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:53:50 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/23 14:07:37 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "asm.h"
#include <stdio.h>

extern t_op g_op_tab[17];

/*
** On verifie que le mnmemonique recupere en dbut d'instruction correspont
** a l'un de ceux dans g_op_tab. Si c'est bon on ajoute l'OPCODE dans le maillon
*/

static int	mnm_compare(char *mnm_line, t_instruction **cursor)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(mnm_line, g_op_tab[i].command) == 0)
		{
			(*cursor)->opcode = g_op_tab[i].op_code;
			return (1);
		}
		i++;
	}
	return (0);
}

/*
** - Pour parser le mnemonique on recupere la chaine de caratere en debut de
** ligne (ligne qui a ete prealablement strimer et d'ou le nom de label a ete
** supprimer)
** - On comapare ensuite notre chaine de caractere avec la list de mnemonique
** dans l'g_op_tap
*/

bool		parse_mnemonique(t_instruction **cursor, char **line)
{
	int		i;
	char	*mnm_line;

	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == TAB || (*line)[i] == SPACE)
		{
			if (!(mnm_line = ft_strnew(i)))
				return (false);
			(*cursor)->start_instr = 1;
			mnm_line = ft_strcpy(mnm_line, ft_strsub(*line, 0, i));
			if (!mnm_compare(mnm_line, cursor))
				return (false);
			*line = ft_strtrim(ft_strsub(*line, i, ft_strlen(*line)));
			return (true);
		}
		i++;
	}
	return (true);
}
