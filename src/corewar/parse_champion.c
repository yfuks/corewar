/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:56:54 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/09 18:20:15 by yfuks            ###   ########.fr       */
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
	return (ft_atoi(nbr));
}

t_champion		*parse_champion(int index, char **av)
{
	int			nbr_champ;
	t_champion	*champion;
	int			i;

	i = index;
	nbr_champ = 0;
	if (!ft_strcmp(av[i], "-n"))
	{
		i++;
		if (!(nbr_champ = check_champion_number(av[i])))
			return (NULL);
		i++;
	}
	if (!(champion = parse_file(av[i])))
		return (NULL);
	champion->player_id = nbr_champ;
	return (champion);
}
