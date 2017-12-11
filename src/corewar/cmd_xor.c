/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_xor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:15:21 by jpascal           #+#    #+#             */
/*   Updated: 2017/12/11 19:20:13 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

#define CMD_XOR_INDEX 7

t_op	g_op_tab[17];

static void		print_xor(int champion_number, int arg1, int arg2, int reg)
{
	print_process_number(champion_number);
	ft_putstr_fd(" | xor ", STD_IN);
	ft_putnbr_fd(arg1, STD_IN);
	ft_putstr_fd(" ", STD_IN);
	ft_putnbr_fd(arg2, STD_IN);
	ft_putstr_fd(" r", STD_IN);
	ft_putnbr_fd(reg, STD_IN);
	ft_putstr_fd("\n", STD_IN);
}

static char		is_reg_valid(t_process *proc, int reg_number, int index)
{
	if (proc->REG[reg_number] <= 0 || proc->REG[reg_number] > REG_NUMBER)
	{
		proc->index = index;
		return (0);
	}
	return (1);
}

static char		check_args(t_process *proc, int i, int index, int args[3])
{
	if (proc->args[i] & T_REG)
	{
		if (!is_reg_valid(proc, i, index))
			return (0);
		if (i <= 2)
			args[i] = proc->registers[proc->REG[i] - 1];
		else
			args[i] = proc->REG[i];
	}
	else if (proc->args[i] & T_DIR)
		args[i] = proc->DIR[i];
	else
		args[i] = proc->IND[i];
	return (1);
}

void			cmd_xor(t_process *proc, t_champion *champion,
						t_arena *arena, t_options *opts)
{
	int		index;
	int		i;
	int		args[3];

	index = next_index(proc->index);
	(void)champion;
	ft_bzero(args, sizeof(int) * 3);
	get_command_arguments(proc, arena, &index, CMD_XOR_INDEX);
	if (!is_reg_valid(proc, 2, index))
		return ;
	i = 0;
	while (i < g_op_tab[CMD_XOR_INDEX].nb_arg - 1)
	{
		if (!check_args(proc, i, index, args))
			return ;
		i++;
	}
	if (opts->verbose & SHOW_OPERATIONS)
		print_xor(proc->number, args[0], args[1], proc->REG[2]);
	proc->registers[proc->REG[2] - 1] = (args[0] ^ args[1]);
	proc->carry = ((args[0] ^ args[1]) == 0) ? 1 : 0;
	proc->index = index;
}
