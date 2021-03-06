/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_deads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:44:12 by jpascal           #+#    #+#             */
/*   Updated: 2017/12/04 19:44:10 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "corewar.h"

int			check_deads(t_arena *arena)
{
	int		i;
	int		is_alive;

	is_alive = 0;
	i = 0;
	while (arena->champions[i].prog_size && i < MAX_PLAYERS)
	{
		if (!arena->champions[i].is_dead)
			is_alive++;
		i++;
	}
	ft_bzero(arena->lives, sizeof(int) * MAX_PLAYERS);
	return (is_alive);
}
