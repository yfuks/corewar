/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:44:53 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/09 16:44:54 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

static char *opts[] = {
	"-dump",
	"-p",
	0
}

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
	int i;

	i = 1;
	if (ac <= 1)
		return (0);
	while (i < ac)
	{

		if (is_options(i, av))
		{
			if (!parse_options(i, av, options))
				return (0);
		}
		else if (!parse_champion(i, av, arena))
				return (0);
		i++;
	}
	return (1);
}
