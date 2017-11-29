/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:55:44 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/29 15:17:54 by yfuks            ###   ########.fr       */
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
		if (cursor->is_dead)
		{
			cursor = cursor->next;
			continue ;
		}
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

static void		reset_process_lives(t_arena *arena)
{
	int			i;
	t_process	*cursor;
	t_champion	*champion;

	i = 0;
	while (i < arena->nb_champs)
	{
		champion = &(arena->champions[i]);
		cursor = champion->process;
		while (cursor)
		{
			cursor->live = 0;
			cursor = cursor->next;
		}
		i++;
	}
}

void		check_process(t_arena *arena, t_options *opts, int cycle_to_die)
{
	int		i;

	i = arena->nb_champs;
	while (i >= 0)
	{
		check_process_in_champion(arena, &arena->champions[i], opts);
		i--;
	}
//	if (cycle_to_die != CYCLE_TO_DIE && cycle_to_die >= CYCLE_DELTA)
	cycle_to_die += CYCLE_DELTA;
	if (arena->should_check_deads)
	{
		check_process_deads(arena, opts, cycle_to_die);
		arena->should_check_deads = 0;
		reset_process_lives(arena);
	}
}
