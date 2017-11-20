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
#include "tools.h"

static void	check_process_in_champion(t_arena *arena, t_champion *champion)
{
	t_process	*cursor;

	cursor = champion->process;
	while (cursor != NULL)
	{
		if (cursor->remaining_cycles == 0)
			exec_command(cursor, champion, arena);
		else
			cursor->remaining_cycles--;
		cursor = cursor->next;
	}
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
