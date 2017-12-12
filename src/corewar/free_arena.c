/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:29:53 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/12 13:37:39 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "op.h"
#include "corewar.h"

static void	free_process(t_champion *champion)
{
	t_process	*cursor;
	t_process	*tmp;

	cursor = champion->process;
	while (cursor)
	{
		tmp = cursor;
		cursor = cursor->next;
		free(tmp);
	}
}

void		free_arena(t_arena *arena)
{
	int		i;

	i = 0;
	free_process(&(arena->champions[0]));
	while (i < arena->nb_champs)
	{
		free(arena->champions[i].name);
		free(arena->champions[i].description);
		i++;
	}
}
