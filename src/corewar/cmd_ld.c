/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:12:56 by jpascal           #+#    #+#             */
/*   Updated: 2017/12/12 11:58:04 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

#define CMD_LD_INDEX 1

static void		print_ld(int champion_number, int reg, int value)
{
	print_process_number(champion_number);
	ft_putstr_fd(" | ld ", STD_IN);
	ft_putnbr_fd(value, STD_IN);
	ft_putstr_fd(" r", STD_IN);
	ft_putnbr_fd(reg, STD_IN);
	ft_putstr_fd("\n", STD_IN);
}

void			cmd_ld(t_process *proc, t_champion *champion,
		t_arena *arena, t_options *opts)
{
	int			index;
	int			index_tmp;

	index = next_index(proc->index);
	index_tmp = 0;
	(void)champion;
	get_command_arguments(proc, arena, &index, CMD_LD_INDEX);
	if (proc->reg[1] > REG_NUMBER || proc->reg[1] <= 0)
	{
		proc->index = index;
		return ;
	}
	if (proc->args[0] == T_IND)
	{
		index_tmp = add_to_index(proc->index, (proc->ind[0] % IDX_MOD));
		proc->registers[(int)(proc->reg[1] - 1)] =
			get_memory(arena, index_tmp, 4);
	}
	else if (proc->args[0] == T_DIR)
		proc->registers[(int)(proc->reg[1] - 1)] = proc->dir[0];
	proc->carry = (0 == proc->registers[(int)(proc->reg[1] - 1)]) ? 1 : 0;
	if (opts->verbose & SHOW_OPERATIONS)
		print_ld(proc->number, proc->reg[1],
	proc->registers[(int)(proc->reg[1] - 1)]);
	proc->index = index;
}
