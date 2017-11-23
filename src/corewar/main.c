/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:57:38 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/23 15:21:48 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

int main(int argc, char **argv)
{
	t_arena		arena;
	t_options	options;
	 int 		i;

	options.dump = -1;
	options.print = 0;
	options.verbose = 0;
	i = 0;
	ft_bzero(&arena, sizeof(arena));
	if (!parse_arguments(argc, argv, &arena, &options))
		return (1);
	if (!init_arena(&arena))
		return (1);
	ft_putstr_fd("Introducing contestants...\n", STD_IN);
	while (arena.champions[i].prog_size)
	{
		print_champ(&arena.champions[i]);
		i++;
	}
	arena.nb_champs = i;
	play(&arena, &options);
	return (0);
}
