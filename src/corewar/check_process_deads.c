/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_process_deads.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:59:00 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/04 19:46:31 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

static void	print_death(t_process *process, t_arena *arena, int ctd)
{
	int		lst_live;

	lst_live = arena->current_cycle - process->last_live;
	ft_putstr_fd("Process ", STD_IN);
	ft_putnbr_fd(process->number, STD_IN);
	ft_putstr_fd(" hasn't lived for ", STD_IN);
	ft_putnbr_fd(lst_live, STD_IN);
	ft_putstr_fd(" cycles (CTD ", STD_IN);
	ft_putnbr_fd(ctd, STD_IN);
	ft_putstr_fd(")\n", STD_IN);
}

void	check_process_deads(t_arena *arena, t_options *opts, int ctd)
{
	t_process	*cursor;
	int			i;
	int			lst_live;
	char		one_alive;

	i = 0;
	while (i < arena->nb_champs)
	{
		one_alive = 0;
		cursor = arena->champions[i].process;
		while (cursor)
		{
			lst_live = arena->current_cycle - cursor->last_live;
			if (!cursor->is_dead && (!cursor->live || arena->is_last_cycle) && lst_live >= ctd)
			{
				cursor->is_dead = 1;
				if (opts->verbose & SHOW_DEATHS)
					print_death(cursor, arena, ctd);
			}
			if (!cursor->is_dead)
			{
				one_alive = 1;
				arena->at_least_one_process_alive = 1;
			}
			cursor = cursor->next;
		}
		if (!one_alive)
			arena->champions[i].is_dead = 1;
		i++;
	}
}
