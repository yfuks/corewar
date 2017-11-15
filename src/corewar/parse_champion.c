/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:56:54 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/13 18:30:29 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "corewar.h"
#include "tools.h"

static int		check_champion_number(char *nbr)
{
	int		i;

	if (!nbr || ft_strlen(nbr) > 10)
		return (0);
	i = 0;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	i = ft_atoi(nbr);
	if (i > 4)
		return (0);
	return (i);
}

t_champion		*parse_champion(char *executable_name, int *index, char **av)
{
	int			nbr_champ;
	t_champion	*champion;

	nbr_champ = 0;
	if (!ft_strcmp(av[*index], "-n"))
	{
		*index += 1;
		if (!(nbr_champ = check_champion_number(av[*index])))
		{
			print_usage(executable_name);
			return (NULL);
		}
		*index += 1;
	}
	if (!(champion = parse_file(av[*index])))
		return (NULL);
	champion->player_id = nbr_champ;
	return (champion);
}
