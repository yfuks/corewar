/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:55:44 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/29 19:36:16 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

t_op op_tab[17];

static void	check_process_in_champion(t_arena *arena, t_champion *champion, t_options *opts)
{
	t_process	*cursor;
	int			encoding;
//	int			opcode;

	cursor = champion->process;
	while (cursor != NULL)
	{
		if (cursor->is_dead)
		{
			cursor = cursor->next;
			continue ;
		}
		if (!cursor->current_opcode)
		{
			cursor->current_opcode = check_opcode(cursor, arena);
			encoding = arena->arena[next_index(cursor->index)];
			cursor->index_opc = cursor->index;
			cursor->index = next_index(cursor->index);
			if (is_valid_param(cursor->current_opcode, encoding))
			{
				if (op_tab[cursor->current_opcode - 1].ocp)
					cursor->index = next_index(cursor->index);
				get_command_arguments(cursor, arena, &(cursor->index), cursor->current_opcode - 1);
			}
			else
			{
				cursor->index = index_jump(cursor->current_opcode, encoding, cursor->index);
				cursor->current_opcode = 0;
				if (opts->verbose & SHOW_PC_MOOV && cursor->current_opcode != 9)
					print_pc_moove(arena, cursor->index_opc, cursor->index);
				cursor->remaining_cycles = 1;
				continue ;
			}
		}
		if (!cursor->current_opcode)
		{
			cursor->index = next_index(cursor->index);
			cursor->remaining_cycles = 1;
		}
		else if (cursor->remaining_cycles == op_tab[cursor->current_opcode - 1].nb_cycles)
		{
			ft_putendl_fd("exec", STD_IN);
			exec_command(cursor, champion, arena, opts);
			cursor->current_opcode = 0;
		}
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

void		check_process(t_arena *arena, t_options *opts, int cycle_to_die, int print)
{
	int		i;

	i = arena->nb_champs;
	while (i >= 0)
	{
		check_process_in_champion(arena, &arena->champions[i], opts);
		i--;
	}
	if (print)
		cycle_to_die += CYCLE_DELTA;
	if (arena->should_check_deads)
	{
		check_process_deads(arena, opts, cycle_to_die);
		arena->should_check_deads = 0;
		reset_process_lives(arena);
	}
}
