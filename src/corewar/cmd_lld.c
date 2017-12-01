/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:14:58 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/28 16:30:23 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

#define CMD_LLD_INDEX 12

static void print_lld(int champion_number, int reg, int value) 
{
	print_process_number(champion_number);
    ft_putstr_fd(" | lld ", STD_IN);
    ft_putnbr_fd(value, STD_IN);
    ft_putstr_fd(" r", STD_IN);
    ft_putnbr_fd(reg, STD_IN);
    ft_putstr_fd("\n", STD_IN);
}

void	   		cmd_lld(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts)
{
    int   index;
    int   index_tmp;
    int   args[2];

    index = next_index(proc->index);
    index_tmp = 0;
    (void)champion;
	ft_bzero(args, sizeof(int) * 2);
    get_command_arguments(proc, arena, &index, CMD_LLD_INDEX);
    if (proc->REG[1] >= REG_NUMBER || !proc->REG[1])
        return ;
    if (proc->args[0] == T_IND)
    {
    	index_tmp = add_to_index(proc->index, proc->IND[0]);
    	args[0] = arena->arena[index_tmp];
    }
    else if (proc->args[0] == T_DIR)
        args[0] = proc->DIR[0];
    if (0 == args[0])
        proc->carry = 1;
    else 
        proc->carry = 0;
    proc->registers[(int)(proc->REG[1] - 1)] = args[0];
    if (opts->verbose & SHOW_OPERATIONS)
        print_lld(proc->number, proc->REG[1], args[0]);
    proc->index = index;
}

