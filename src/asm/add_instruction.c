/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:44:37 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/15 14:39:51 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"
#include "tools.h"

t_instruction  *add_end_instruction(t_instruction **list_instr)
{
	t_instruction *cursor;

	cursor = *list_instr;
	if (*list_instr)
	{
		while (cursor && cursor->next)
			cursor = cursor->next;
		if (!(cursor->next = (t_instruction*)malloc(sizeof(t_instruction))))
			return (NULL);
		// (cursor)->next->prev = cursor;
		return (cursor->next);
	}
	else
		*list_instr = ft_memalloc(sizeof(t_instruction));
	return (*list_instr);
}
