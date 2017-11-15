/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:13:19 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/15 14:58:47 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"
#include <unistd.h>

// void	get_mnm(t_instruction **cursor, char *line)
// {
// 	int 	i;
// 	char	*mnm_compare;
// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == TAB || line[i] == space)
// 		{
// 			if(!(mnm_compare = ft_strnew(i)))
// 				return ;
// 			mnm_compare = ft_strcpy(mnm_compare, )
// 		}
// 		i++;
// 	}
//
// }

bool	parse_instruction(t_instruction **list_instr, t_instruction *cursor, char *line)
{

	if (!(ft_strcmp((line = ft_strtrim(line)), "")))
		return (true);
	if (cursor->label != NULL)
		line = ft_strtrim(ft_strsub(line, ft_strlen(cursor->label) + 1, ft_strlen(line)));
	if (cursor->double_label != NULL)
		line = ft_strtrim(ft_strsub(line, ft_strlen(cursor->double_label) + 1, ft_strlen(line)));
	// get_mnm(&cursor, line))
	// printf("mnm : '%s'\n", cursor->mnm);
	list_instr = NULL;
	return (true);
}
