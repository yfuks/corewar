/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_process_lives.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:17:07 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/05 17:17:31 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		reset_process_lives(t_arena *arena)
{
	int			i;
	t_process	*cursor;
	t_champion	*champion;

	i = 0;
	while (i < arena->nb_champs)
	{
		champion = &(arena->champions[i]);
		cursor = champion->process;
		while (cursor)
		{
			cursor->live = 0;
			cursor = cursor->next;
		}
		i++;
	}
}
