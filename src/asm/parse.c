/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:42:33 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/15 12:16:30 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"

t_hstate	ft_zero_state(t_hstate *state)
{
	state->name = 0;
	state->comment = 0;
	return (*state);
}


bool 	parse_first_read(t_header *header, t_instruction **list_instr, int fd, t_hstate *state)
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
		printf("%zu : %s\n",cursor->nb_line , cursor->label);
	}
	return (true);
}


bool 	parse_second_read(t_instruction **list_instr, int fd)
{
	char			*line;
	t_instruction 	*cursor;
	int				ret_gnl;

	printf("ici\n");
	cursor = *list_instr;
	printf("%zu : %s\n",cursor->nb_line , cursor->label);

	while ((ret_gnl = get_next_line(fd, &line)) == 1)
	{
		printf("ret_gnl : %d\n",ret_gnl);
		while (cursor->start_instr == 0)
			cursor = cursor->next;
		printf("%zu : %s\n",cursor->nb_line , cursor->label);
		break;
		// if (cursor->start_instr = 1)
		// {
		//
		// }
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
		return (1);
	if(!(parse_second_read(list_instr, fd)))
		return (false);
	return (true);
}
