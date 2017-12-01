/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_process_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:16:02 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/28 16:33:31 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void		print_process_number(int number)
{
	char		spaces[5];
	int			tmp;
	int			i;

	i = 3;
	spaces[0] = ' ';
	spaces[1] = ' ';
	spaces[2] = ' ';
	spaces[3] = ' ';
	spaces[4] = 0;
	ft_putstr_fd("P", STD_IN);
	tmp = number;
	while (tmp >= 10 && i >= 0)
	{
		spaces[i] = 0;
		i--;
		tmp /= 10;
	}
	ft_putstr_fd(spaces, STD_IN);
	ft_putnbr_fd(number, STD_IN);
}
