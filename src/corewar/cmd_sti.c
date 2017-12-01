/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:07:53 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/28 16:30:58 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

#define CMD_STI_INDEX 10

t_op op_tab[17];

static void print_sti(int champion_number, int reg, int addr1, int addr2)
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

static void     print_infos(int addr1, int addr2, int index)
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

void	   		cmd_sti(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts)
{
  int   index;
  int   i;
  int   index_tmp;
  int   args[3];

  (void)champion;
  index = next_index(proc->index);
  get_command_arguments(proc, arena, &index, CMD_STI_INDEX);
  if (proc->REG[0] >= REG_NUMBER || !proc->REG[0])
    return ;
  i = 1;
  while (i < op_tab[CMD_STI_INDEX].nb_arg)
  {
      if (proc->args[i] == T_DIR)
        args[i - 1] = proc->DIR[i];
      else if (proc->args[i] == T_IND)
        args[i - 1] = proc->IND[i];
       else if (proc->args[i] == T_REG)
        args[i - 1] = proc->registers[proc->REG[i] - 1];
      i++;
  }
  if (opts->verbose & SHOW_OPERATIONS)
	  print_sti(proc->number, proc->REG[0], args[0], args[1]);
  i = (args[0] + args[1]) % IDX_MOD;
  index_tmp = add_to_index(proc->index, (args[0] + args[1]) % IDX_MOD);
  if (opts->verbose & SHOW_OPERATIONS)
	  print_infos(args[0], args[1], proc->index + i);
  copy_int_to_arena(arena, proc->registers[(int)(proc->REG[0] - 1)], index_tmp);
  proc->index = index;
}
