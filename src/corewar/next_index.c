/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:15:22 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/07 16:49:08 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int     next_index(int index)
{
	if (index == MEM_SIZE - 1)
        return (0);
    return (index + 1);
}

int     prev_index(int index)
{
    if (index == 0)
        return (MEM_SIZE - 1);
    return (index - 1);
}
