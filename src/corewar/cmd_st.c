/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_st.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:13:05 by jpascal           #+#    #+#             */
/*   Updated: 2017/12/05 18:51:08 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

#define CMD_ST_INDEX 2

static void print_st(int champion_number, int reg, int addr1) 
{
	print_process_number(champion_number);
    ft_putstr_fd(" | st r", STD_IN);
    ft_putnbr_fd(reg, STD_IN);
    ft_putstr_fd(" ", STD_IN);
    ft_putnbr_fd(addr1, STD_IN);
    ft_putstr_fd("\n", STD_IN);
}

void	   		cmd_st(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts)
{
    int   index;
    int   index_tmp;
    int   args[2];

	(void)champion;
    index = next_index(proc->index);
    ft_bzero(args, sizeof(int) * 2);
    index_tmp = 0;
    get_command_arguments(proc, arena, &index, CMD_ST_INDEX);
    if (proc->REG[0] > REG_NUMBER || proc->REG[0] <= 0 || proc->REG[1] > REG_NUMBER)
	{
		proc->index = index;
        return ;
	}
    args[0] = proc->registers[(int)proc->REG[0] - 1];
    if (proc->args[1] == T_REG)
    {
		if (proc->REG[1] <= 0)
		{
			proc->index = index;
			return ;
		}
        proc->registers[(int)proc->REG[1] - 1] = args[0];
        if (opts->verbose & SHOW_OPERATIONS)
            print_st(proc->number, proc->REG[0], proc->REG[1]);
    }
    else if (proc->args[1] == T_IND)
    {
        index_tmp = add_to_index(proc->index, (proc->IND[1] % IDX_MOD));
        copy_int_to_arena(arena, args[0], index_tmp);
        if (opts->verbose & SHOW_OPERATIONS)
            print_st(proc->number, proc->REG[0], proc->IND[1]);
    }
    proc->index = index;
}
