/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_champ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:17:53 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/11 18:17:54 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

void		print_champ(t_champion *champion)
{
	ft_putstr_fd("* Player ", STD_IN);
	ft_putnbr_fd(champion->player_id, STD_IN);
	ft_putstr_fd(", weighing ", STD_IN);
	ft_putnbr_fd(champion->prog_size, STD_IN);
	ft_putstr_fd(" bytes, \"", STD_IN);
	ft_putstr_fd(champion->name, STD_IN);
	ft_putstr_fd("\" (\"", STD_IN);
	ft_putstr_fd(champion->description, STD_IN);
	ft_putendl_fd("\") !", STD_IN);
}
