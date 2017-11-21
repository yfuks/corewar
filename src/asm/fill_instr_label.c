/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_instr_label.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:46:31 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/21 14:13:48 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>

bool	error_fill_instr_label(t_instruction **cursor)
{
	ft_putstr_fd("line:", 2);
	ft_putnbr_fd((*cursor)->nb_line, 2);
	ft_putstr_fd(" Error label of instruction does not exist\n", 2);
	return(false);
}

bool	fill_instr_label(t_instruction **list_instr, t_instruction **cursor, int i)
{
	t_instruction *tmp;

	tmp = *list_instr;
	while (tmp && tmp->next)
	{
		if (ft_strcmp((*cursor)->arg[i] + 1, tmp->label) == 0)
		{
			(*cursor)->arg_value[i] = tmp->instr_byte_size - (*cursor)->instr_byte_size;
			return (true);
		}
		tmp = tmp->next;
	}
	return (error_fill_instr_label(cursor));
}
