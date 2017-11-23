/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:15:22 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/20 12:15:23 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int     next_index(int index)
{
    if (index == MEM_SIZE)
        return (0);
    return (index + 1);
}

int     prev_index(int index)
{
    if (index == 0)
        return (0);
    return (index - 1);
}
