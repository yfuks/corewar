/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_bytes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 08:32:53 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/17 11:46:23 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>

/*
** le nobre d'octets se calcule :
- Opcode = 1
- Si octet de codage, octet de codage = 1
- Registe = 1 octet (T_REG)
- Indirect = 2 octets
- Direct = 2 ou 4 octets
*/

void ft_count_bytes(t_instruction **cursor)
{
	int i;

	(*cursor)->instr_byte_size = 1;
	if ((*cursor)->opcode != 1 && (*cursor)->opcode != 9 && (*cursor)->opcode != 12 && (*cursor)->opcode != 15)
		(*cursor)->instr_byte_size += 1;
	i = 0;
	if ((*cursor)->opcode != 1 && (*cursor)->opcode != 2
		&& (*cursor)->opcode != 6 && (*cursor)->opcode != 7
		&& (*cursor)->opcode != 8 && (*cursor)->opcode != 13)
	{
		while ((*cursor)->arg_type[i] && i < 3)
		{
			if ((*cursor)->arg_type[i] == T_REG)
				(*cursor)->instr_byte_size += 1;
			else
				(*cursor)->instr_byte_size += 2;
			i++;
		}
	}
	else
	{
		while ((*cursor)->arg_type[i]  && i < 3)
		{
			if ((*cursor)->arg_type[i] == T_REG)
				(*cursor)->instr_byte_size += 1;
			else if ((*cursor)->arg_type[i] == T_IND)
				(*cursor)->instr_byte_size += 2;
			else
				(*cursor)->instr_byte_size += 4;
			i++;
		}
	}
}

void 	ft_count_cumul(t_instruction **list_instr)
{
	t_instruction 	*tmp;
	int 			cumul;

	cumul = 0;
	tmp = *list_instr;
	while (tmp && tmp->next)
	{
		cumul = tmp->cumul_byte_size;
		tmp = tmp->next;
		tmp->cumul_byte_size = cumul + tmp->instr_byte_size;
	}
}
