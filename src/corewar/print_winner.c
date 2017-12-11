/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_winner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:22:07 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/11 17:52:30 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "corewar.h"

static void	print_victory(t_champion *champion)
{
	ft_putstr_fd("Contestant ", STD_IN);
	ft_putnbr_fd(champion->player_id, STD_IN);
	ft_putstr_fd(", \"", STD_IN);
	ft_putstr_fd(champion->name, STD_IN);
	ft_putstr_fd("\", has won !\n", STD_IN);
}

void		print_winner(t_arena *arena)
{
	if (arena->last_live)
	{
		print_victory(&(arena->champions[arena->last_live - 1]));
		return ;
	}
	print_victory(&(arena->champions[arena->nb_champs - 1]));
}
