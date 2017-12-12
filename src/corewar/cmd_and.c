/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:53:46 by jpascal           #+#    #+#             */
/*   Updated: 2017/12/12 11:56:42 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

#define CMD_AND_INDEX 5

t_op g_op_tab[17];

static void		print_and(int champion_number, int arg1, int arg2, int reg)
{
	print_process_number(champion_number);
	ft_putstr_fd(" | and ", STD_IN);
	ft_putnbr_fd(arg1, STD_IN);
	ft_putstr_fd(" ", STD_IN);
	ft_putnbr_fd(arg2, STD_IN);
	ft_putstr_fd(" r", STD_IN);
	ft_putnbr_fd(reg, STD_IN);
	ft_putstr_fd("\n", STD_IN);
}

static void		get_cmd_and_args(t_process *proc, int *args, int index)
{
	int			i;

	i = 0;
	while (i < g_op_tab[CMD_AND_INDEX].nb_arg - 1)
	{
		if (proc->args[i] & T_REG)
		{
			if (proc->reg[i] <= 0 || proc->reg[i] > REG_NUMBER)
			{
				proc->index = index;
				return ;
			}
			if (i <= 2)
				args[i] = proc->registers[proc->reg[i] - 1];
			else
				args[i] = proc->reg[i];
		}
		else if (proc->args[i] & T_DIR)
			args[i] = proc->dir[i];
		else
			args[i] = proc->ind[i];
		i++;
	}
}

void			cmd_and(t_process *proc, t_champion *champion, t_arena *arena,
		t_options *opts)
{
	int			index;
	int			args[3];

	(void)champion;
	index = next_index(proc->index);
	ft_bzero(args, sizeof(int) * 3);
	get_command_arguments(proc, arena, &index, CMD_AND_INDEX);
	if (proc->reg[2] <= 0 || proc->reg[2] > REG_NUMBER)
	{
		proc->index = index;
		return ;
	}
	get_cmd_and_args(proc, args, index);
	if (opts->verbose & SHOW_OPERATIONS)
		print_and(proc->number, args[0], args[1], proc->reg[2]);
	proc->registers[proc->reg[2] - 1] = (args[0] & args[1]);
	if ((args[0] & args[1]) == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->index = index;
}
