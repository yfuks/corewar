/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:49:08 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/24 14:18:08 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

#define CMD_ADD_INDEX 3

static void		print_add(int champion_number, int reg1, int reg2, int reg3)
{
	ft_putstr_fd("P    ", STD_IN);
    ft_putnbr_fd(champion_number, STD_IN);
	ft_putstr_fd(" | add r", STD_IN);
	ft_putnbr_fd(reg1, STD_IN);
	ft_putstr_fd(" r", STD_IN);
	ft_putnbr_fd(reg2, STD_IN);
	ft_putstr_fd(" r", STD_IN);
	ft_putnbr_fd(reg3, STD_IN);
	ft_putstr_fd("\n", STD_IN);
}

void            cmd_add(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts)
{
	int		index;
	int		value;

	index = next_index(proc->index);
	get_command_arguments(proc, arena, &index, CMD_ADD_INDEX);
	if (!proc->REG[0] || !proc->REG[1] || !proc->REG[2]
		|| proc->REG[0] >= REG_NUMBER
		|| proc->REG[1] >= REG_NUMBER || proc->REG[2] >= REG_NUMBER)
		return ;
	value = champion->registers[proc->REG[0] - 1] + champion->registers[proc->REG[1] - 1];
	champion->registers[proc->REG[2] - 1] = value;
	if (opts->verbose & SHOW_OPERATIONS)
		print_add(champion->player_id, proc->REG[0], proc->REG[1], proc->REG[2]);
	if (value >= 0)
		champion->carry = 1;
	else
		champion->carry = 0;
	proc->index = index;
}
