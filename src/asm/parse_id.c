/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:56:33 by alansiva          #+#    #+#             */
/*   Updated: 2017/12/01 12:17:10 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tools.h"
#include <stdio.h>

bool		error_id(int n)
{
	if (n == 1)
		ft_putstr_fd("name or comment command must start with a .\n", 2);
	if (n == 2)
		ft_putstr_fd("command does not exist\n", 2);
	if (n == 3)
		ft_putstr_fd("Char \" can't be in comment or name string\n", 2);
	if (n == 4)
		ft_putstr_fd("Name not well formated\n", 2);
	if (n == 5)
		ft_putstr_fd("Comment not well formated\n", 2);
	return (false);
}

/*
** - On enleve les SPACE et TAB au debut et fin de ligne
** - On regarde si les premier caractere correspondent bien a .c et .n
** - On compare si la chaine apres le . correspondent a "comment ou name"
** en faisant attention au variable d'etat
** - On enleve les SPACE et TAB au debut et fin de ligne
** - On rempli la strucure header par le nom ou commentaire
*/

static bool	parse_id_name(t_header *header, char *line, t_hstate *state)
{
	char	*compare_name;

	if (!(compare_name = ft_strnew(5)))
		return (false);
	if (!(compare_name = ft_strncpy(compare_name, line, 5)))
		return (false);
	if (ft_strcmp(NAME_CMD_STRING, compare_name) == 1)
	{
		ft_memdel((void**)&compare_name);
		return (error_id(2));
	}
	else
	{
		line = ft_trim(ft_strsub2(line, 5, ft_strlen(line)));
		if (!(fill_id_name(header, line, state)))
			return (false);
	}
	ft_memdel((void**)&compare_name);
	return (true);
}

static bool	parse_id_comment(t_header *header, char *line, t_hstate *state)
{
	char	*compare_comment;

	if (!(compare_comment = ft_strnew(8)))
		return (false);
	if (!(compare_comment = ft_strncpy(compare_comment, line, 8)))
		return (false);
	if (ft_strcmp(COMMENT_CMD_STRING, compare_comment) == 1)
	{
		ft_memdel((void**)&compare_comment);
		return (error_id(2));
	}
	else
	{
		line = ft_trim(ft_strsub2(line, 8, ft_strlen(line)));
		if (!(fill_id_com(header, line, state)))
			return (false);
	}
	ft_memdel((void**)&compare_comment);
	return (true);
}

bool		parse_id(t_header *header, char *line, t_hstate *state)
{
	if (!(ft_strcmp(line, "")) || !(ft_strcmp((line = ft_trim(line)), "")))
		return (true);
	if (ft_strcmp(line, "\0") == 0)
		return (true);
	if (line[0] != '.')
		return (error_id(1));
	if (line[1] != 'n' && line[1] != 'c')
		return (error_id(2));
	if (line[1] == 'n' && state->name == 0)
	{
		if (!(parse_id_name(header, line, state)))
			return (false);
	}
	else if (line[1] == 'c' && state->comment == 0)
	{
		if (!(parse_id_comment(header, line, state)))
			return (false);
	}
	return (true);
}
