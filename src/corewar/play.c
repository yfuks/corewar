/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:18:33 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/16 11:18:34 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"
#include "op.h"

static int		check_total_lives(int lives[MAX_PLAYERS])
{
	int			i;
	int 		total_lives;

	i = 0;
	total_lives = 0;
	while (i < MAX_PLAYERS)
	{
		total_lives += lives[i];
		i++;
	}
	return (total_lives);
}

static int		next_cycle(t_arena *arena, int cycle_to_die, t_options *options)
{
	int 	cycle;

	cycle = cycle_to_die;
	while (cycle > 0)
	{
		if (options->dump == arena->current_cycle)
		{
			print_map_arena(arena);
			return (0);
		}
		check_process(arena);
		arena->current_cycle += 1;
		cycle--;
	}
	return (1);
}

void		play(t_arena *arena, t_options *options)
{
	int 	cycle_to_die;
	int 	nb_live;
	int		checks;

	checks = 0;
	cycle_to_die = CYCLE_TO_DIE;
	while (cycle_to_die >= CYCLE_DELTA)
	{
		if (!next_cycle(arena, cycle_to_die, options))
			return ;
		nb_live = check_total_lives(arena->lives);
		if (check_deads(arena))
			return ;
		checks++;
		if (arena->current_cycle != CYCLE_TO_DIE
			&& (checks == MAX_CHECKS || nb_live >= NBR_LIVE))
		{
			checks = 0;
			cycle_to_die -= CYCLE_DELTA;
		}
	}
}
