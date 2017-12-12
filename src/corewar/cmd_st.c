/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_st.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:13:05 by jpascal           #+#    #+#             */
/*   Updated: 2017/12/12 11:57:20 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

#define CMD_ST_INDEX 2

static void	print_st(int champion_number, int reg, int addr1)
{
	print_process_number(champion_number);
	ft_putstr_fd(" | st r", STD_IN);
	ft_putnbr_fd(reg, STD_IN);
	ft_putstr_fd(" ", STD_IN);
	ft_putnbr_fd(addr1, STD_IN);
	ft_putstr_fd("\n", STD_IN);
}

static char	is_reg_valid(t_process *proc, int reg_number, int index)
{
	if (proc->reg[reg_number] <= 0 || proc->reg[reg_number] > REG_NUMBER)
	{
		proc->index = index;
		return (0);
	}
	return (1);
}

static void	inits(t_process *proc, t_arena *arena, int *index, int *index_tmp)
{
	*index = next_index(proc->index);
	*index_tmp = 0;
	get_command_arguments(proc, arena, index, CMD_ST_INDEX);
}

static void	show_if_options(t_process *proc, t_options *opts, int ar1, int ar2)
{
	if (opts->verbose & SHOW_OPERATIONS)
		print_st(proc->number, ar1, ar2);
}

void		cmd_st(t_process *proc, t_champion *champion,
				t_arena *arena, t_options *opts)
{
	int		index;
	int		index_tmp;
	int		args[2];

	(void)champion;
	ft_bzero(args, sizeof(int) * 2);
	inits(proc, arena, &index, &index_tmp);
	if (!is_reg_valid(proc, 0, index))
		return ;
	args[0] = proc->registers[(int)proc->reg[0] - 1];
	if (proc->args[1] == T_REG)
	{
		if (!is_reg_valid(proc, 1, index))
			return ;
		proc->registers[(int)proc->reg[1] - 1] = args[0];
		show_if_options(proc, opts, proc->reg[0], proc->reg[1]);
	}
	else if (proc->args[1] == T_IND)
	{
		index_tmp = add_to_index(proc->index, (proc->ind[1] % IDX_MOD));
		copy_int_to_arena(arena, args[0], index_tmp);
		show_if_options(proc, opts, proc->reg[0], proc->ind[1]);
	}
	proc->index = index;
}
