/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:56:33 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/28 15:00:58 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tools.h"
#include <stdio.h>

static bool	error_id(int n)
{
	if (n == 1)
		ft_putstr_fd("name or comment command must start with a .\n", 2);
	if (n == 2)
		ft_putstr_fd("command does not exist\n", 2);
	if (n == 3)
		ft_putstr_fd("Char \" can't be in comment or name string\n", 2);
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
	char 	*name;
	char 	*name2;

	name = NULL;
	name2 = NULL;
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
		name = ft_strsub(line, 5, ft_strlen(line));
		name2 = ft_strtrim(name);
		if (!(fill_id_name(header, name2, state)))
			return (error_id(3));
	}
	ft_memdel((void**)&compare_name);
	ft_memdel((void**)&name);
	ft_memdel((void**)&name2);
	return (true);
}

static bool	parse_id_comment(t_header *header, char *line, t_hstate *state)
{
	char	*compare_comment;
	char *comment;
	char *comment2;

	comment = NULL;
	comment2 = NULL;
	if (!(compare_comment = ft_strnew(8)))
		return (false);
	if (!(compare_comment = ft_strncpy(compare_comment, line, 8)))
		return (false);
	if (ft_strcmp(COMMENT_CMD_STRING, compare_comment) == 1)
		return (error_id(2));
	else
	{
		comment = ft_strsub(line, 8, ft_strlen(line));
		comment2 = ft_strtrim(comment);
		if (!(fill_id_com(header, comment2, state)))
			return (error_id(3));
	}
	ft_memdel((void**)&compare_comment);
	ft_memdel((void**)&comment);
	ft_memdel((void**)&comment2);
	return (true);
}

bool		parse_id(t_header *header, char *line, t_hstate *state)
{
	char	*id;

	id = ft_strtrim(line);
	if (ft_strcmp(id, "\0") == 0)
		return (true);
	if (id[0] != '.')
		return (error_id(1));
	if (id[1] != 'n' && id[1] != 'c')
		return (error_id(2));
	if (id[1] == 'n' && state->name == 0)
	{
		if (!(parse_id_name(header, id, state)))
			return (false);
	}
	else if (id[1] == 'c' && state->comment == 0)
	{
		if (!(parse_id_comment(header, id, state)))
			return (false);
	}
	ft_memdel((void**)&id);
	return (true);
}
