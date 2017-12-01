/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_int_in_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:42:14 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/22 13:42:16 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void        split_int_in_char(char integer[4], unsigned int value)
{
    integer[3] = value & 0xFF;
    integer[2] = (value >> 8) & 0xFF;
    integer[1] = (value >> 16) & 0xFF;
    integer[0] = (value >> 24) & 0xFF;
}
