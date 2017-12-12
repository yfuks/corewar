/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_endian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:59:08 by jthillar          #+#    #+#             */
/*   Updated: 2017/12/04 19:44:02 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>

uint16_t	swap_uint16(uint16_t val)
{
	return (val << 8 | val >> 8);
}

uint32_t	swap_uint32(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return ((val << 16) | (val >> 16));
}
