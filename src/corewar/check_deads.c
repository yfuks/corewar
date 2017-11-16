/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_deads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:44:12 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/16 13:44:15 by jpascal          ###   ########.fr       */
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
		if (arena->lives[i] == 0)
			arena->champions[i].is_dead = 1;
		else 
			is_alive++;
		i++;
	}
	return (is_alive);
}