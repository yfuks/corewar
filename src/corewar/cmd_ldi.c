/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:48:59 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/12 12:02:18 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

#define CMD_LDI_INDEX 9

static void		print_ldi(int champion_number, int value, int value2, int reg)
{
	print_process_number(champion_number);
	ft_putstr_fd(" | ldi ", STD_IN);
	ft_putnbr_fd(value, STD_IN);
	ft_putstr_fd(" ", STD_IN);
	ft_putnbr_fd(value2, STD_IN);
	ft_putstr_fd(" r", STD_IN);
	ft_putnbr_fd(reg, STD_IN);
	ft_putstr_fd("\n", STD_IN);
}

static void		print_infos(int value, int value2, int total)
{
	ft_putstr_fd("       | -> load from ", STD_IN);
	ft_putnbr_fd(value, STD_IN);
	ft_putstr_fd(" + ", STD_IN);
	ft_putnbr_fd(value2, STD_IN);
	ft_putstr_fd(" = ", STD_IN);
	ft_putnbr_fd(value + value2, STD_IN);
	ft_putstr_fd(" (with pc and mod ", STD_IN);
	ft_putnbr_fd(total, STD_IN);
	ft_putstr_fd(")\n", STD_IN);
}

static void		get_cmd_ldi_args(t_process *proc, int index, t_arena *arena,
	int *args)
{
	int			i;
	int			index_tmp;

	index_tmp = 0;
	i = -1;
	while (i++ < 2)
	{
		if (proc->args[i] == T_REG)
		{
			if (proc->reg[i] > REG_NUMBER || proc->reg[i] <= 0)
			{
				proc->index = index;
				return ;
			}
			args[i] = proc->registers[proc->reg[i] - 1];
		}
		else if (proc->args[i] == T_DIR)
			args[i] = proc->dir[i];
		else if (proc->args[i] == T_IND)
		{
			args[i] = (proc->ind[i] % IDX_MOD);
			index_tmp = add_to_index(proc->index, args[i]);
			args[i] = get_memory(arena, index_tmp, 4);
		}
	}
}

void			cmd_ldi(t_process *proc, t_champion *champion, t_arena *arena,
	t_options *opts)
{
	int			index;
	int			args[3];
	int			i;
	int			index_tmp;

	index = next_index(proc->index);
	(void)champion;
	ft_bzero(args, sizeof(int) * 3);
	get_command_arguments(proc, arena, &index, CMD_LDI_INDEX);
	if (proc->reg[2] > REG_NUMBER || proc->reg[2] <= 0)
	{
		proc->index = index;
		return ;
	}
	get_cmd_ldi_args(proc, index, arena, args);
	i = (args[0] + args[1]) % IDX_MOD;
	index_tmp = add_to_index(proc->index, (args[0] + args[1]) % IDX_MOD);
	if (opts->verbose & SHOW_OPERATIONS)
	{
		print_ldi(proc->number, args[0], args[1], proc->reg[2]);
		print_infos(args[0], args[1], proc->index + i);
	}
	i = get_memory(arena, index_tmp, REG_SIZE);
	proc->registers[proc->reg[2] - 1] = i;
	proc->index = index;
}
