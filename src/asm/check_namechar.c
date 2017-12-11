/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_namechar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:29:50 by jthillar          #+#    #+#             */
/*   Updated: 2017/12/01 12:17:54 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "asm.h"

bool	check_namechar(char *line, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (line[i] == '\"')
			return (false);
		i++;
	}
	return (true);
}

/*
** - On rempli la strucure header par le nom et on change la variable d'etat
** car le nom a ete donne
*/

bool	fill_id_name(t_header *header, char *line, t_hstate *state)
{
	if (line[0] != '\"' || line[ft_strlen(line) - 1] != '"')
		return (error_id(4));
	else
	{
		line++;
		state->name = 1;
		if (!(check_namechar(line, ft_strlen(line) - 1)))
			return (error_id(3));
		ft_strncpy(&(*header->prog_name), line, ft_strlen(line) - 1);
	}
	return (true);
}

/*
** - On rempli la strucure header par le commentaire et on change la variable
** d'etat car le commentaire a ete donne
*/

bool	fill_id_com(t_header *header, char *line, t_hstate *state)
{
	if (line[0] != '\"' || line[ft_strlen(line) - 1] != '\"')
		return (error_id(5));
	else
	{
		line++;
		state->comment = 1;
		if (!(check_namechar(line, ft_strlen(line) - 1)))
			return (error_id(3));
		ft_strncpy(&(*header->comment), line, ft_strlen(line) - 1);
	}
	return (true);
}
