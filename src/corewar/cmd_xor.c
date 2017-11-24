/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_xor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:15:21 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/23 18:15:22 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

#define CMD_XOR_INDEX 7

t_op op_tab[17];

static void     print_xor(int champion_number, int arg1, int arg2, int reg)
{
    ft_putstr_fd("P    ", STD_IN);
    ft_putnbr_fd(champion_number, STD_IN);
    ft_putstr_fd(" | or ", STD_IN);
    ft_putnbr_fd(arg1, STD_IN);
    ft_putstr_fd(" ", STD_IN);
    ft_putnbr_fd(arg2, STD_IN);
    ft_putstr_fd(" r", STD_IN);
    ft_putnbr_fd(reg, STD_IN);
    ft_putstr_fd("\n", STD_IN);
}

void	   		cmd_xor(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts)
{
    int   index;
    int   i;
    int   args[3];

    index = next_index(proc->index);
    ft_bzero(args, sizeof(int) * 3);
    get_command_arguments(proc, arena, &index, CMD_XOR_INDEX);
    if (proc->REG[0] >= REG_NUMBER || proc->REG[1] >= REG_NUMBER || proc->REG[2] >= REG_NUMBER)
      return ;
    i = 0;
    while (i < op_tab[CMD_XOR_INDEX].nb_arg - 1)
    {
        if (proc->args[i] & T_REG)
        {
            if (i <= 2)
                args[i] = champion->registers[proc->REG[i] - 1];
            else
                args[i] = proc->REG[i];
        }
        else if (proc->args[i] & T_DIR)
            args[i] = proc->DIR[i];
        else
            args[i] = proc->IND[i];
        i++;
    }
	if (opts->verbose & SHOW_OPERATIONS)
		print_xor(champion->player_id, args[0], args[1], proc->REG[2]);
    champion->registers[proc->REG[2] - 1] = (args[0] ^ args[1]);
    if (args[0] ^ args[1])
        champion->carry = 1;
    proc->index = index;
}