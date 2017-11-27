/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo_idx_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:20:29 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/27 14:25:25 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

int			modulo_idx_mod(int value)
{
	int		ret;

	if (value >= 0)
		ret = value % IDX_MOD;
	else
	{
		ret = (value * -1) % IDX_MOD;
		ret *= -1;
	}
	ft_putnbr_fd(ret, STD_IN);
	ft_putstr_fd("\n", STD_IN);
	return (ret);
}
