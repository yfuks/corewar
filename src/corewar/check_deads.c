/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_deads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:44:12 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/28 17:59:46 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "corewar.h"

static void print_victory(t_champion *champion)
{
	ft_putstr_fd("Contestant ", STD_IN);
	ft_putnbr_fd(champion->player_id, STD_IN);
	ft_putstr_fd(", \"", STD_IN);
	ft_putstr_fd(champion->name, STD_IN);
	ft_putstr_fd("\", has won !\n", STD_IN);
}

static void	print_winner(t_arena *arena)
{
	if (arena->last_live)
	{
		print_victory(&(arena->champions[arena->last_live - 1]));
		return ;
	}
	print_victory(&(arena->champions[arena->nb_champs - 1]));
}

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

static void	check_process_dead(t_champion *champion, t_arena *arena, int ctd, t_options *opts)
{
	t_process	*cursor;

	cursor = champion->process;
	while (cursor)
	{
		if (!cursor->is_dead && !cursor->live)
		{
			cursor->is_dead = 1;
			if (opts->verbose & SHOW_DEATHS)
				print_death(cursor, arena, ctd);
		}
		cursor = cursor->next;
	}
}

int			check_deads(t_arena *arena, t_options *opts, int cycle_to_die)
{
	int		i;
	int		is_alive;

	is_alive = 0;
	i = 0;
	while (arena->champions[i].prog_size && i < MAX_PLAYERS)
	{
		check_process_dead(&(arena->champions[i]), arena, cycle_to_die, opts);
		if (arena->lives[i] == 0)
		{
			arena->champions[i].is_dead = 1;
			//print_death(&(arena->champions[i]), arena, cycle_to_die);
		}
		else 
			is_alive++;
		i++;
	}
	if (!is_alive)
		print_winner(arena);
	return (is_alive);
}
