/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_int_to_arena.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:43:05 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/22 13:43:10 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

void        copy_int_to_arena(t_arena *arena, unsigned int value, int index)
{
    int     i;
    char    integer[4];

    i = 0;
    ft_bzero(integer, sizeof(char) * 4);
    split_int_in_char(integer, value);
    while (i < 4)
    {
        arena->arena[index] = integer[i];
        index = next_index(index);
        i++;
    }
}
