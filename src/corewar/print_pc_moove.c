/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pc_moove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:42:13 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/27 17:44:03 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

static int	get_size(int from, int to)
{
	int		size;

	size = 0;
	while (from < to)
	{
		from = next_index(from);
		size++;
	}
	return (size);
}

void		print_pc_moove(t_arena *arena, int from, int to)
{
	int		size;
	int		i;
	int		tmp;

	size = get_size(from, to);
	ft_putstr_fd("ADV ", STD_IN);
	ft_putnbr_fd(size, STD_IN);
	ft_putstr_fd(" (0x", STD_IN);
	ft_put_hex_fd(from, STD_IN, 4);
	ft_putstr_fd(" -> 0x", STD_IN);
	ft_put_hex_fd(to, STD_IN, 4);
	ft_putstr_fd(") ", STD_IN);
	i = 0;
	while (i < size)
	{
		tmp = arena->arena[from];
		ft_put_hex_fd(tmp, STD_IN, 2);
		from = next_index(from);
		ft_putstr_fd(" ", STD_IN);
		i++;
	}
	ft_putstr_fd("\n", STD_IN);
}
