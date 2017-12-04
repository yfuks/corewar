/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lfork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:10:25 by jpascal           #+#    #+#             */
/*   Updated: 2017/12/01 18:42:07 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

static void		print_lfork(int champion_number, int ind, int total)
{
	print_process_number(champion_number);
	ft_putstr_fd(" | lfork ", STD_IN);
	ft_putnbr_fd(ind, STD_IN);
	ft_putstr_fd(" (", STD_IN);
	ft_putnbr_fd(total, STD_IN);
	ft_putstr_fd(")\n", STD_IN);
}

void            cmd_lfork(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts)
{
	int			index;
	int			index_tmp;
	int 		value;
	t_process	*process;

	index = next_index(proc->index);
	value = get_memory(arena, index, 2);
	index_tmp = add_to_index(proc->index, value);
	if (opts->verbose & SHOW_OPERATIONS)
		print_lfork(proc->number, value, index_tmp);
	proc->index = add_to_index(index, 2);
	process = new_process(index_tmp);
	process->carry = proc->carry;
	process->last_live = arena->current_cycle - 1000;
	ft_memcpy(process->registers, proc->registers, sizeof(int) * REG_NUMBER);
	process->remaining_cycles = 1;
	add_process_to_champion(champion, process);
}
