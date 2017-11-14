/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_arena.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:14:51 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/14 18:14:53 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

#define STD_OUT 1

void	print_map_arena(t_arena *arena)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_put_hex_fd(arena->arena[i], STD_OUT);
		ft_putstr_fd(" ", STD_OUT);
		if ((i + 1) % 64 == 0 && i > 0)
			ft_putstr_fd("\n", STD_OUT);
		i++;
	}
	//ft_putstr_fd("\n", STD_OUT);
}