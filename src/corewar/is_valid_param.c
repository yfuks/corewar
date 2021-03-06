/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:15:29 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/11 18:39:21 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

t_op	g_op_tab[17];

int		is_valid_param(int cmd_opcode, char encoding)
{
	int		i;
	char	tmp;

	if (!g_op_tab[cmd_opcode - 1].ocp)
		return (1);
	i = 0;
	while (i < g_op_tab[cmd_opcode - 1].nb_arg)
	{
		tmp = encoding >> (6 - (i * 2));
		tmp = tmp & 0x3;
		if ((g_op_tab[cmd_opcode - 1].args_types[i] & T_IND)
			&& (tmp == IND_CODE))
			;
		else if ((g_op_tab[cmd_opcode - 1].args_types[i] & T_DIR)
				&& (tmp == DIR_CODE))
			;
		else if ((g_op_tab[cmd_opcode - 1].args_types[i] & T_REG)
				&& (tmp == REG_CODE))
			;
		else
			return (0);
		i++;
	}
	return (1);
}
