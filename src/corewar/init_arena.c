/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:08:36 by jpascal           #+#    #+#             */
/*   Updated: 2017/12/07 19:22:52 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

#define	STD_ERR 2

static int	print_champion_number_not_valid(t_champion champion)
{
	ft_putstr_fd("Champion: ", STD_ERR);
	ft_putstr_fd(champion.name, STD_ERR);
	ft_putstr_fd(" has a number bigger than the ", STD_ERR);
	ft_putstr_fd("number of champions : ", STD_ERR);
	ft_putnbr_fd(champion.player_id, STD_ERR);
	ft_putstr_fd("\n", STD_ERR);
	return (0);
}

static int	number_taken(int j, t_champion champions[MAX_PLAYERS])
{
	int		i;

	i = 0;
	while (champions[i].prog_size && i < MAX_PLAYERS)
	{
		if (champions[i].player_id == (unsigned int)j)
			return (1);
		i++;
	}
	return (0);
}

static int 	check_valid_champions_id(t_arena *arena)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (arena->champions[i].prog_size && i < MAX_PLAYERS)
		i++;
	while (arena->champions[j].prog_size && i < MAX_PLAYERS)
	{
		if (arena->champions[j].player_id > (unsigned int)i)
			return (print_champion_number_not_valid(arena->champions[j]));
		j++;
	}
	return (1);
}

static int		init_champions_id(t_arena *arena)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (arena->champions[i].prog_size && i < MAX_PLAYERS)
	{
		if (arena->champions[i].player_id == 0)
		{
			while (number_taken(j, arena->champions))
				j++;
			arena->champions[i].player_id = j;
		}
		i++;
	}
	return (i);
}

int			init_arena(t_arena *arena)
{
	int nb_champions;
	int i;
	int size;
	int position;
	t_process *process;

	position = 0;
	i = 0;
	if (!check_valid_champions_id(arena))
		return (0);
	nb_champions = init_champions_id(arena);
	size = MEM_SIZE / nb_champions;
	while (i < nb_champions)
	{
		ft_memcpy(&arena->arena[position], arena->champions[i].code, \
		arena->champions[i].prog_size);
		if (!(process = new_process(position)))
			return (0);
		process->registers[0] = (arena->champions[i].player_id * -1);
		add_process_to_champion(&(arena->champions[0]), process);
		position += size;
		i++;
	}
	return (1);
}
