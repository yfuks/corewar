/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:07:53 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/12 11:55:16 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

#define CMD_STI_INDEX 10

t_op	g_op_tab[17];

static void		print_sti(int champion_number, int reg, int addr1, int addr2)
{
	print_process_number(champion_number);
	ft_putstr_fd(" | sti r", STD_IN);
	ft_putnbr_fd(reg, STD_IN);
	ft_putstr_fd(" ", STD_IN);
	ft_putnbr_fd(addr1, STD_IN);
	ft_putstr_fd(" ", STD_IN);
	ft_putnbr_fd(addr2, STD_IN);
	ft_putstr_fd("\n", STD_IN);
}

static void		print_infos(int addr1, int addr2, int index)
{
	ft_putstr_fd("       | -> store to ", STD_IN);
	ft_putnbr_fd(addr1, STD_IN);
	ft_putstr_fd(" + ", STD_IN);
	ft_putnbr_fd(addr2, STD_IN);
	ft_putstr_fd(" = ", STD_IN);
	ft_putnbr_fd(addr1 + addr2, STD_IN);
	ft_putstr_fd(" (with pc and mod ", STD_IN);
	ft_putnbr_fd(index, STD_IN);
	ft_putstr_fd(")\n", STD_IN);
}

static char		is_reg_valid(t_process *proc, int reg_number, int index)
{
	if (proc->reg[reg_number] <= 0 || proc->reg[reg_number] > REG_NUMBER)
	{
		proc->index = index;
		return (0);
	}
	return (1);
}

static char		check_args(t_process *proc, int i, int index, int args[3])
{
	if (proc->args[i] == T_DIR)
		args[i - 1] = proc->dir[i];
	else if (proc->args[i] == T_IND)
		args[i - 1] = proc->ind[i];
	else if (proc->args[i] == T_REG)
	{
		if (!is_reg_valid(proc, i, index))
			return (0);
		args[i - 1] = proc->registers[proc->reg[i] - 1];
	}
	return (1);
}

void			cmd_sti(t_process *proc, t_champion *champion,
						t_arena *arena, t_options *opts)
{
	int		index[2];
	int		index_tmp;
	int		args[3];

	(void)champion;
	index[0] = next_index(proc->index);
	get_command_arguments(proc, arena, &index[0], CMD_STI_INDEX);
	if (!is_reg_valid(proc, 0, index[0]))
		return ;
	index[1] = 1;
	while (index[1] < g_op_tab[CMD_STI_INDEX].nb_arg)
	{
		if (!check_args(proc, index[1], index[0], args))
			return ;
		index[1]++;
	}
	if (opts->verbose & SHOW_OPERATIONS)
		print_sti(proc->number, proc->reg[0], args[0], args[1]);
	index[1] = (args[0] + args[1]) % IDX_MOD;
	index_tmp = add_to_index(proc->index, (args[0] + args[1]) % IDX_MOD);
	if (opts->verbose & SHOW_OPERATIONS)
		print_infos(args[0], args[1], proc->index + index[1]);
	copy_int_to_arena(arena, proc->registers[(int)(proc->reg[0] - 1)],
					index_tmp);
	proc->index = index[0];
}
