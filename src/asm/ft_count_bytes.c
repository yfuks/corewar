/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_bytes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 08:32:53 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/24 08:52:28 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>

/*
** le nobre d'octets se calcule :
** - Opcode = 1
** - Si octet de codage, octet de codage = 1
** - Registe = 1 octet (T_REG)
** - Indirect = 2 octets
** - Direct = 2 ou 4 octets
*/

static void	count_direct_special(t_instruction **cursor, int i)
{
	if ((*cursor)->arg_type[i] == T_REG)
	{
		(*cursor)->arg_size[i] = 1;
		(*cursor)->instr_byte_size += 1;
	}
	else
	{
		(*cursor)->arg_size[i] = 2;
		(*cursor)->instr_byte_size += 2;
	}
}

static void	count_direct(t_instruction **cursor, int i)
{
	if ((*cursor)->arg_type[i] == T_REG)
	{
		(*cursor)->arg_size[i] = 1;
		(*cursor)->instr_byte_size += 1;
	}
	else if ((*cursor)->arg_type[i] == T_IND)
	{
		(*cursor)->arg_size[i] = 2;
		(*cursor)->instr_byte_size += 2;
	}
	else
	{
		(*cursor)->arg_size[i] = 4;
		(*cursor)->instr_byte_size += 4;
	}
}

void		ft_count_bytes(t_instruction **cursor)
{
	int i;

	(*cursor)->instr_byte_size = 1;
	if ((*cursor)->opcode != 1 && (*cursor)->opcode != 9 &&
	(*cursor)->opcode != 12 && (*cursor)->opcode != 15)
		(*cursor)->instr_byte_size += 1;
	i = 0;
	if ((*cursor)->opcode != 1 && (*cursor)->opcode != 2
		&& (*cursor)->opcode != 6 && (*cursor)->opcode != 7
		&& (*cursor)->opcode != 8 && (*cursor)->opcode != 13)
	{
		while ((*cursor)->arg_type[i] && i < 3)
		{
			count_direct_special(cursor, i);
			i++;
		}
	}
	else
	{
		while ((*cursor)->arg_type[i] && i < 3)
		{
			count_direct(cursor, i);
			i++;
		}
	}
}
