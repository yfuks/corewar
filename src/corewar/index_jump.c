/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_jump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:38:49 by jpascal           #+#    #+#             */
/*   Updated: 2017/12/11 18:45:34 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

t_op	g_op_tab[17];

static int		new_index(int index_tmp, int index)
{
	int			i;

	i = 0;
	while (i < index_tmp)
	{
		index = next_index(index);
		i++;
	}
	return (index);
}

int				index_jump(int opcode, char encoding, int index)
{
	char		tmp;
	int			index_tmp;
	int			size_direct;
	int			i;

	index_tmp = 1;
	size_direct = 2;
	i = 0;
	if (opcode == 1 || opcode == 2 || opcode == 3 || opcode == 4 || opcode == 5
		|| opcode == 6 || opcode == 7 || opcode == 8 || opcode == 9
		|| opcode == 13)
		size_direct = 4;
	while (i < g_op_tab[opcode - 1].nb_arg)
	{
		tmp = encoding >> (6 - (i * 2));
		tmp = tmp & 0x3;
		if (tmp == IND_CODE)
			index_tmp += IND_SIZE;
		else if (tmp == DIR_CODE)
			index_tmp += size_direct;
		else if (tmp == REG_CODE)
			index_tmp += REG_CODE;
		i++;
	}
	return (new_index(index_tmp, index));
}
