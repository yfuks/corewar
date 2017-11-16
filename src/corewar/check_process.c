/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:55:44 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/16 15:55:47 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	check_process_in_champion(t_arena *arena, t_champion *champion)
{
	t_process	**head;

	head = &champion->process;
	while (champion->process)
	{
		if (champion->process->remaining_cycles == 0)
			exec_command(champion->process, champion, arena);
		else
			champion->process->remaining_cycles--;
		champion->process = champion->process->next;
	}
	champion->process = *head;
}

void		check_process(t_arena *arena)
{
	int		i;

	i = 0;
	while (arena->champions[i].prog_size && i < MAX_PLAYERS)
	{
		check_process_in_champion(arena, &arena->champions[i]);
		i++;
	}
}