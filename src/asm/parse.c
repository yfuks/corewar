/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:42:33 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/16 11:50:09 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"
#include <fcntl.h>
#include <stdio.h>

static t_hstate	ft_zero_state(t_hstate *state)
{
	state->name = 0;
	state->comment = 0;
	return (*state);
}

static bool 	parse_first_read(t_header *header, t_instruction **list_instr, int fd, t_hstate *state)
{
	char			*line;
	t_instruction	*cursor;
	int				ret_gnl;
	int 			nb_line;

	nb_line = 0;
	while ((ret_gnl = get_next_line(fd, &line)) == 1)
	{
		nb_line++;
		cursor = add_end_instruction(list_instr);
		cursor->nb_line = nb_line;
		check_commentchar(&line);
		if (state->name < 1 || state->comment < 1)
		{
			if (!parse_id(header, line, state))
			return (false);
		}
		else
		{
			cursor->start_instr = 1;
			parse_label(list_instr, cursor, line);
		}
	}
	return (true);
}

static bool 	parse_second_read(t_instruction **list_instr, int fd)
{
	char			*line;
	t_instruction 	*cursor;
	int				ret_gnl;

	cursor = *list_instr;
	while ((ret_gnl = get_next_line(fd, &line)) == 1)
	{
		if (cursor && cursor->start_instr == 0)
			cursor = cursor->next;
		else
		{
			check_commentchar(&line);
			if(!(parse_instruction(list_instr, cursor, line)))
				return (false);
			if (cursor && cursor->next)
				cursor = cursor->next;
		}
	}
	return (true);
}


bool	parse(t_header *header, t_instruction **list_instr, int fd, char *filename)
{
	t_hstate	state;

	state = ft_zero_state(&state);
	if(!(parse_first_read(header, list_instr, fd, &state)))
		return (false);
	if((fd = open(filename, O_RDONLY)) == -1)
		return (false);
	if(!(parse_second_read(list_instr, fd)))
		return (false);
	return (true);
}
