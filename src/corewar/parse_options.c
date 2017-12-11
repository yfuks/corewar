/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:21:49 by jpascal           #+#    #+#             */
/*   Updated: 2017/12/11 18:19:19 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "corewar.h"
#include <limits.h>

static int		is_valid_dump_arg(int index, char **av)
{
	int		i;

	i = 0;
	if (!av[index + 1])
		return (0);
	while (av[index + 1] && av[index + 1][i] != '\0')
	{
		if (!ft_isdigit(av[index + 1][i]))
			return (0);
		i++;
	}
	if (ft_strlen(av[index + 1]) > 10 || ft_atol(av[index + 1]) < 0 ||
		ft_atol(av[index + 1]) > INT_MAX)
		return (0);
	return (1);
}

static int		is_valid_verbose_arg(int index, char **av)
{
	int		i;

	i = 0;
	if (!av[index + 1])
		return (0);
	while (av[index + 1] && av[index + 1][i] != '\0')
	{
		if (!ft_isdigit(av[index + 1][i]))
			return (0);
		i++;
	}
	if (ft_strlen(av[index + 1]) > 10 || ft_atol(av[index + 1]) < 0 ||
		ft_atol(av[index + 1]) > INT_MAX)
		return (0);
	return (1);
}

int				parse_options(int *index, char **av, t_options *options)
{
	if (ft_strcmp(av[*index], "-dump") == 0)
	{
		if (!is_valid_dump_arg(*index, av))
			return (0);
		*index += 1;
		options->dump = ft_atoi(av[*index]);
	}
	else if (ft_strcmp(av[*index], "-p") == 0)
		options->print = 1;
	else if (ft_strcmp(av[*index], "-a") == 0)
		options->aff = 1;
	else if (ft_strcmp(av[*index], "-v") == 0)
	{
		if (!is_valid_verbose_arg(*index, av))
			return (0);
		*index += 1;
		options->verbose = ft_atoi(av[*index]);
	}
	return (1);
}
