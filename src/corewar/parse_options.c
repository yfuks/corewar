/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:21:49 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/09 17:21:50 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "corewar.h"
#include <limits.h>

static int				is_dump(int index, char **av)
{
	if (av[index + 1])
		if (ft_strlen(av[index + 1]) < 10 && ft_atoi(av[index + 1]) > 0)
			return (1);
	return (0);
}

int				parse_options(int index, char **av, t_options *options)
{
	if (ft_strcmp(av[index], "-dump") == 0)
	{
		if (!is_dump(index, av))
			return (0);
		else
			options->dump = ft_atoi(av[index + 1]);
	}
	else if (ft_strcmp(av[index], "-print") == 0)
		options->print = 1;
	return (1);
}
