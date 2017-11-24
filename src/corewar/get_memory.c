/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:04:27 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/24 15:08:05 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

int		get_memory(t_arena *arena, int index, int size)
{
	int		value;
	char	integer[4];
	int		i;

	value = 0;
	i = 0;
	while (i < size)
	{
		integer[i] = arena->arena[index];
		index = next_index(index);
		i++;
	}
	if (size <= 2)
		value = ctos(integer);
	else
		value = ctoi(integer);
	return (value);
}
