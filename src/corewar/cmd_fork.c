/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:10:25 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/24 16:10:28 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

static void		print_fork(int champion_number, int ind, int total)
{
	ft_putstr_fd("P    ", STD_IN);
    ft_putnbr_fd(champion_number, STD_IN);
	ft_putstr_fd(" | fork ", STD_IN);
	ft_putnbr_fd(ind, STD_IN);
	ft_putstr_fd(" (", STD_IN);
	ft_putnbr_fd(total, STD_IN);
	ft_putstr_fd(")\n", STD_IN);
}

void            cmd_fork(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts)
{
	int			index;
	int			index_tmp;
	int 		value;
	t_process	*process;

	index = next_index(proc->index);
	value = get_memory(arena, index, 2);
	index_tmp = add_to_index(proc->index, value % IDX_MOD);
	if (opts->verbose & SHOW_OPERATIONS)
		print_fork(champion->player_id, value, index_tmp);
	proc->index = add_to_index(index, 2);
	process = new_process(index_tmp);
	add_process_to_champion(champion, process);
}