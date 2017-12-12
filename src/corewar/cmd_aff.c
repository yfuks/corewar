/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_aff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:36:54 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/12 12:02:42 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

#define CMD_AFF_INDEX 15

static void		print_aff(char value)
{
	ft_putstr_fd("Aff: ", STD_IN);
	ft_putchar_fd(value, STD_IN);
	ft_putstr_fd("\n", STD_IN);
}

void			cmd_aff(t_process *proc, t_champion *champion, t_arena *arena,
	t_options *opts)
{
	int			index;

	(void)champion;
	ft_bzero(&proc->reg, sizeof(int) * 3);
	index = next_index(proc->index);
	get_command_arguments(proc, arena, &index, CMD_AFF_INDEX);
	if (proc->reg[0] >= REG_NUMBER || !proc->reg[0])
	{
		proc->index = next_index(proc->index);
		return ;
	}
	if (opts->aff == 1)
		print_aff(proc->registers[proc->reg[0] - 1] % 256);
	proc->index = index;
}
