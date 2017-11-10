/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_champion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:58:41 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/10 15:16:51 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "corewar.h"
#include "tools.h"

t_champion      *new_champion(char *name, char *description)
{
	t_champion	*champion;

	if (!(champion = (t_champion *)malloc(sizeof(t_champion))))
		return (NULL);
	ft_bzero(champion, sizeof(t_champion));
	if (!(champion->name = ft_strdup(name)))
		return (NULL);
	if (!(champion->description = ft_strdup(description)))
		return (NULL);
	return (champion);
}
