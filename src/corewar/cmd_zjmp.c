/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_zjmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:43:03 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/27 13:38:31 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

static void		print_zjmp(int champion_number, int ind)
{
	ft_putstr_fd("P    ", STD_IN);
    ft_putnbr_fd(champion_number, STD_IN);
	ft_putstr_fd(" | zjmp ", STD_IN);
	ft_putnbr_fd(ind, STD_IN);
	ft_putstr_fd(" OK\n", STD_IN);
}

static void		print_zjmp_failed(int champion_number, int ind)
{
	ft_putstr_fd("P    ", STD_IN);
    ft_putnbr_fd(champion_number, STD_IN);
	ft_putstr_fd(" | zjmp ", STD_IN);
	ft_putnbr_fd(ind, STD_IN);
	ft_putstr_fd(" FAILED\n", STD_IN);
}

void            cmd_zjmp(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts)
{
	int		index;
	char	integer[IND_SIZE];
	int		count;
	int		ind;

	(void)champion;
	index = next_index(proc->index);
	ft_bzero(integer, sizeof(char) * IND_SIZE);
	count = 0;
	while (count < IND_SIZE)
	{
		integer[count] = arena->arena[index];
		index = next_index(index);
		count++;
	}
	ind = ctos(integer);
	if (!proc->carry)
	{
		if (opts->verbose & SHOW_OPERATIONS)
			print_zjmp_failed(proc->number, (ind % IDX_MOD));
		proc->index = index;
		return ;
	}
	if (opts->verbose & SHOW_OPERATIONS)
		print_zjmp(proc->number, (ind % IDX_MOD));
	index = add_to_index(proc->index, (ind % IDX_MOD));
	proc->index = index;
}
