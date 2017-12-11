/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:35:26 by jpascal           #+#    #+#             */
/*   Updated: 2017/12/11 20:02:44 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

#define CMD_LLDI_INDEX 13

static void		print_lldi(int champion_number, int value, int value2, int reg)
{
	print_process_number(champion_number);
	ft_putstr_fd(" | lldi ", STD_IN);
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
	ft_putstr_fd(" (with pc ", STD_IN);
	ft_putnbr_fd(value + value2 + total, STD_IN);
	ft_putstr_fd(")\n", STD_IN);
}

static int		get_cmd_lldi_args(t_process *proc, t_options *opts,
		t_arena *arena, int *args)
{
	int			i;
	int			index_tmp;

	i = 0;
	index_tmp = add_to_index(proc->index, args[0] + args[1]);
	if (opts->verbose & SHOW_OPERATIONS)
	{
		print_lldi(proc->number, args[0], args[1], proc->REG[2]);
		print_infos(args[0], args[1], proc->index);
	}
	while (i < 2)
	{
		if (proc->args[i] == T_REG)
			args[i] = proc->registers[proc->REG[i] - 1];
		else if (proc->args[i] == T_DIR)
			args[i] = proc->DIR[i];
		else if (proc->args[i] == T_IND)
		{
			args[i] = (proc->IND[i]);
			index_tmp = add_to_index(proc->index, args[i]);
			args[i] = get_memory(arena, index_tmp, 4);
		}
		i++;
	}
	return (index_tmp);
}

void			cmd_lldi(t_process *proc, t_champion *champion, t_arena *arena,
		t_options *opts)
{
	int		index;
	int		args[3];
	int		i;
	int		index_tmp;

	index = next_index(proc->index);
	index_tmp = 0;
	(void)champion;
	ft_bzero(args, sizeof(int) * 3);
	get_command_arguments(proc, arena, &index, CMD_LLDI_INDEX);
	if (proc->REG[2] >= REG_NUMBER || !proc->REG[2])
	{
		proc->index = index;
		return ;
	}
	index_tmp = get_cmd_lldi_args(proc, opts, arena, args);
	i = get_memory(arena, index_tmp, REG_SIZE);
	proc->registers[proc->REG[2] - 1] = i;
	proc->carry = (proc->registers[proc->REG[2] - 1] == i) ? 1 : 0;
	proc->index = index;
}
