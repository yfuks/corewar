/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:55:44 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/23 15:42:52 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

t_op op_tab[17];

static void	check_process_in_champion(t_arena *arena, t_champion *champion, t_options *opts)
{
	t_process	*cursor;
	int			opcode;

	cursor = champion->process;
	while (cursor != NULL)
	{
		if (!(opcode = check_opcode(cursor, arena)))
		{
			cursor->index = next_index(cursor->index);
			cursor->remaining_cycles = 1;
		}
		else if (cursor->remaining_cycles == op_tab[opcode - 1].nb_cycles)
			exec_command(cursor, champion, arena, opts);
		else
			cursor->remaining_cycles++;
		cursor = cursor->next;
	}
}

void		check_process(t_arena *arena, t_options *opts)
{
	int		i;

	i = arena->nb_champs;
	while (i >= 0)
	{
		check_process_in_champion(arena, &arena->champions[i], opts);
		i--;
	}
}
