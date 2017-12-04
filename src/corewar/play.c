/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:18:33 by jpascal           #+#    #+#             */
/*   Updated: 2017/12/04 20:02:54 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"
#include "op.h"

static int		next_cycle(t_arena *arena, int cycle_to_die, t_options *options, int print)
{
	int 	cycle;

	cycle = cycle_to_die;
	if (cycle_to_die <= 0 || arena->is_last_cycle)
		cycle = 1;
	if (arena->current_cycle)
		arena->current_cycle += 1;
	while (cycle > 0)
	{
		if (options->verbose & SHOW_CYCLES && arena->current_cycle)
		{
			ft_putstr_fd("It is now cycle ", STD_IN);
			ft_putnbr_fd(arena->current_cycle, STD_IN);
			ft_putstr_fd("\n", STD_IN);
		}
		if (!check_process(arena, options, cycle_to_die, print))
			return (0);
		if (print && options->verbose & SHOW_CYCLES && ((cycle == cycle_to_die)
				|| (cycle_to_die <= 0 && cycle == 1)))
		{
			ft_putstr_fd("Cycle to die is now ", STD_IN);
			ft_putnbr_fd(cycle_to_die, STD_IN);
			ft_putstr_fd("\n", STD_IN);
			print = 0;
		}
		if (options->dump == arena->current_cycle)
		{
			print_map_arena(arena);
			return (0);
		}
		cycle--;
		if (cycle > 0)
			arena->current_cycle += 1;
	}
	return (1);
}

void		play(t_arena *arena, t_options *options)
{
	int 	cycle_to_die;
	int 	nb_live;
	int		checks;
	int		print;

	checks = 0;
	print = 0;
	cycle_to_die = CYCLE_TO_DIE;
	while (1)
	{
		if (!next_cycle(arena, cycle_to_die, options, print))
			return ;
		nb_live = arena->nb_lives;
		checks++;
		print = 0;
		if (arena->current_cycle > CYCLE_TO_DIE)
		{
			arena->should_check_deads = 1;
			if (!check_deads(arena) || cycle_to_die <= 0)
			{
				arena->is_last_cycle = 1;
				next_cycle(arena, cycle_to_die, options, print);
				return ;
			}
		}
		if (nb_live > NBR_LIVE || checks >= MAX_CHECKS)
		{
			checks = 0;
			cycle_to_die -= CYCLE_DELTA;
			print = 1;
		}
		arena->nb_lives = 0;
	}
}
