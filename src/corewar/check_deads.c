/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_deads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:44:12 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/23 14:01:27 by yfuks            ###   ########.fr       */
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

int			check_deads(t_arena *arena)
{
	int		i;
	int		is_alive;
	
	is_alive = 0;
	i = 0;
	while (arena->champions[i].prog_size && i < MAX_PLAYERS)
	{
		if (arena->lives[i] == 0)
			arena->champions[i].is_dead = 1;
		else 
			is_alive++;
		i++;
	}
	if (!is_alive)
		print_winner(arena);
	return (is_alive);
}
