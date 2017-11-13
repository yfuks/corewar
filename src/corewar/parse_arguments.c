/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:44:53 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/13 13:55:21 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "corewar.h"
#include "tools.h"

static char *opts[] = {
	"-dump",
	"-p",
	0
};

static int		is_options(int index, char **av)
{
	int		i;

	i = 0;
	while (opts[i])
	{
		if (!ft_strcmp(av[index], opts[i]))
			return (1);
		i++;
	}
	return (0);
}

int				parse_arguments(int ac, char **av, t_arena *arena, t_options *options)
{
	int 		i;
	t_champion	*champion;

	i = 1;
	(void)arena;
	champion = NULL;
	if (ac <= 1)
		return (print_usage(av[0]));
	while (i < ac)
	{
		if (is_options(i, av))
		{
			if (!parse_options(i, av, options))
				return (print_usage(av[0]));
			else
				if (options->dump != -1)
					i += 1;
		}
		else
		{
			if (!(champion = parse_champion(i, av)))
				return (0);
//			add_champion_in_arena(champion, arena);
		}
		i++;
	}
	return (1);
}