/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_champion_in_arena.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:35:26 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/14 15:35:28 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "corewar.h"
#include "tools.h"

#define STD_ERR 2

static int	print_too_many_champion(void)
{
	ft_putstr_fd("Too many champions\n", STD_ERR);
	return (0);
}

static int	print_champion_number_already_taken(t_champion *champion)
{
	ft_putstr_fd("Champion: ", STD_ERR);
	ft_putstr_fd(champion->name, STD_ERR);
	ft_putstr_fd(" has a number already taken: ", STD_ERR);
	ft_putnbr_fd(champion->player_id, STD_ERR);
	ft_putstr_fd("\n", STD_ERR);
	return (0);
}

int		add_champion_in_arena(t_champion *champion, t_arena *arena)
{
	int		i;

	i = 0;
	while (arena->champions[i].prog_size && i < MAX_PLAYERS)
	{
		if (arena->champions[i].player_id == champion->player_id && champion->player_id)
			return (print_champion_number_already_taken(champion));
		i++;
	}
	if (i >= MAX_PLAYERS)
		return (print_too_many_champion());
	arena->champions[i] = *champion;
	return (1);
}