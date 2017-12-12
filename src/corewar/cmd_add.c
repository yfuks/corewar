/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:49:08 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/12 12:00:40 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

#define CMD_ADD_INDEX 3

static void		print_add(int champion_number, int reg1, int reg2, int reg3)
{
	print_process_number(champion_number);
	ft_putstr_fd(" | add r", STD_IN);
	ft_putnbr_fd(reg1, STD_IN);
	ft_putstr_fd(" r", STD_IN);
	ft_putnbr_fd(reg2, STD_IN);
	ft_putstr_fd(" r", STD_IN);
	ft_putnbr_fd(reg3, STD_IN);
	ft_putstr_fd("\n", STD_IN);
}

void			cmd_add(t_process *proc, t_champion *champion, t_arena *arena,
	t_options *opts)
{
	int			index;
	int			value;

	index = next_index(proc->index);
	(void)champion;
	get_command_arguments(proc, arena, &index, CMD_ADD_INDEX);
	if (proc->reg[0] <= 0 || proc->reg[1] <= 0 || proc->reg[2] <= 0
		|| proc->reg[0] > REG_NUMBER
		|| proc->reg[1] > REG_NUMBER || proc->reg[2] > REG_NUMBER)
	{
		proc->index = index;
		return ;
	}
	value = proc->registers[proc->reg[0] - 1] +
	proc->registers[proc->reg[1] - 1];
	proc->registers[proc->reg[2] - 1] = value;
	if (opts->verbose & SHOW_OPERATIONS)
		print_add(proc->number, proc->reg[0], proc->reg[1], proc->reg[2]);
	if (value == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->index = index;
}
