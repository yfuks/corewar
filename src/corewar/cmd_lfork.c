/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lfork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:17:04 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/29 19:32:03 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

static void		print_fork(int champion_number, int ind, int total)
{
	print_process_number(champion_number);
	ft_putstr_fd(" | fork ", STD_IN);
	ft_putnbr_fd(ind, STD_IN);
	ft_putstr_fd(" (", STD_IN);
	ft_putnbr_fd(total, STD_IN);
	ft_putstr_fd(")\n", STD_IN);
}

static void		cpy_registers(t_process *proc, t_process *new)
{
	int		i;

	i = 0;
	while (i < REG_NUMBER)
	{
		new->registers[i] = proc->registers[i];
		i++;
	}
}

void            cmd_lfork(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts)
{
//	int			index;
	int			index_tmp;
	int 		value;
	t_process	*process;

	(void)arena;
//	index = next_index(proc->index);
//	value = get_memory(arena, index, 2);
	value = proc->DIR[0];
	index_tmp = add_to_index(proc->index_opc, value);
	if (opts->verbose & SHOW_OPERATIONS)
		print_fork(proc->number, value, index_tmp);
//	proc->index = add_to_index(index, 2);
	process = new_process(index_tmp);
	process->carry = proc->carry;
	cpy_registers(proc, process);
	process->remaining_cycles = 1;
	add_process_to_champion(champion, process);
}
