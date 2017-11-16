/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mnemonique.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:53:50 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/16 15:12:18 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "asm.h"
#include <stdio.h>

extern t_op g_op_tab[17];

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
			mnm_line = ft_strcpy(mnm_line, ft_strsub(*line, 0, i));
			if (!mnm_compare(mnm_line, cursor))
				return (false);
			*line = ft_strtrim(ft_strsub(*line, i, ft_strlen(*line)));
		}
		i++;
	}
	// printf("cursor->opcode : %d		line : '%s'\n", (*cursor)->opcode, *line);
	return (true);
}
