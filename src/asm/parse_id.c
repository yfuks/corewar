/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:56:33 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/15 15:06:56 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tools.h"

static void	fill_id_name(t_header *header, char *line, t_hstate *state)
{
	if (line[0] != '\"' && line[ft_strlen(line) - 1] != '\"')
		return ;
	else
	{
		line++;
		state->name = 1;
		if (!(check_namechar(line, ft_strlen(line) - 1)))
			return ;
		ft_strncpy(&(*header->prog_name), line, ft_strlen(line) - 1);
		// printf("header->prog_name '%s'\n", header->prog_name);
	}
}

static void	fill_id_com(t_header *header, char *line, t_hstate *state)
{
	if (line[0] != '\"' && line[ft_strlen(line) - 1] != '\"')
		return ;
	else
	{
		line++;
		state->comment = 1;
		if (!(check_namechar(line, ft_strlen(line) - 1)))
			return ;
		ft_strncpy(&(*header->comment), line, ft_strlen(line) - 1);
	}
}

bool	parse_id(t_header *header, char *line, t_hstate *state)
{
	char 	*compare_name;
	char 	*compare_comment;

	line = ft_strtrim(line);
	if (line[0] != '.')
		return (false);
	if (line[1] != 'n' && line[1] != 'c')
		return (false);
	if (line[1] == 'n' && state->name == 0)
	{
		if (!(compare_name = ft_strnew(5)))
			return (false);
		if(!(compare_name = ft_strncpy(compare_name, line, 5)))
			return (false);
		if (ft_strcmp(NAME_CMD_STRING, compare_name) == 1)
			return (false);
		else
		{
			line = ft_strtrim(ft_strsub(line, 5, ft_strlen(line)));
			// printf("line '%s'\n", line);
			fill_id_name(header, line, state);
		}
	}
	else if (line[1] == 'c' && state->comment == 0)
	{
		if (!(compare_comment = ft_strnew(8)))
			return (false);
		if(!(compare_comment = ft_strncpy(compare_comment, line, 8)))
			return (false);
		if (ft_strcmp(COMMENT_CMD_STRING, compare_comment) == 1)
			return (false);
		else
		{
			line = ft_strtrim(ft_strsub(line,  8, ft_strlen(line)));
			fill_id_com(header, line, state);
		}
	}
	return (true);
}
