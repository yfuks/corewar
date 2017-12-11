/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:57:15 by jpascal           #+#    #+#             */
/*   Updated: 2017/12/11 17:57:17 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int         add_to_index(int index, int nbr)
{
    int     i;

    i = 0;
    if (nbr > 0)
    {
        while (i < nbr)
        {
            index = next_index(index);
            i++;
        }
    }
    else if (nbr < 0)
    {
        while (i > nbr)
        {
            index = prev_index(index);
            i--;
        }
    }
    return (index);
}