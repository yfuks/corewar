/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:57:38 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/13 17:44:30 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

int main(int argc, char **argv)
{
	t_arena		arena;
	t_options	options;

	options.dump = -1;
	options.print = 0;
	ft_bzero(&arena, sizeof(arena));
	if (!parse_arguments(argc, argv, &arena, &options))
		return (1);
	return (0);
}
