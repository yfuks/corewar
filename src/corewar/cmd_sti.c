/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:07:53 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/18 16:07:54 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

#define CMD_STI_INDEX 10

t_op op_tab[17];

void	   		cmd_sti(t_process *proc, t_champion *champion, t_arena *arena)
{
  int   index;
  int   i;
  int   index_tmp;
  int   addr;

  index = next_index(proc->index);
  get_command_arguments(proc, arena, &index, CMD_STI_INDEX);
  if (proc->REG[0] >= REG_NUMBER)
    return ;
  i = 1;
  addr = 0;
  while (i < op_tab[CMD_STI_INDEX].nb_arg)
  {
      if (proc->DIR[i])
        addr += proc->DIR[i];
      else
        addr += proc->IND[i];
      i++;
  }
  index_tmp = add_to_index(proc->index, addr);
  copy_int_to_arena(arena, champion->registers[(int)(proc->REG[0] - 1)], index_tmp);
  proc->index = index;
}
