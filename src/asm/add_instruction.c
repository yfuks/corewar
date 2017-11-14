/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:44:37 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/14 12:17:10 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"

void  add_end_instruction(t_instruction **list_instr)
{
	if (*list_instr)
	{
		while (*list_instr && (*list_instr)->next)
			*list_instr = (*list_instr)->next;
		if (!((*list_instr)->next = (t_instruction*)malloc(sizeof(t_instruction))))
			return;
		*list_instr = (*list_instr)->next;
	}
	*list_instr = ft_memalloc(sizeof(t_instruction));
}
