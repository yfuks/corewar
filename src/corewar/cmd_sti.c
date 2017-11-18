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



void	   		cmd_sti(t_process *proc, t_champion *champion, t_arena *arena)
{
  char  encoding;

  encoding = arena->arena[proc->index + 1];
  (void)champion;
}
