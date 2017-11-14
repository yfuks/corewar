/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:42:33 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/14 18:28:54 by jthillar         ###   ########.fr       */
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

bool	parse(t_header *header, t_instruction **list_instr, int fd)
{
	int			ret_gnl;
	t_instruction *cursor;
	char		*line;
	t_hstate	state;
	int 		nb_line;

	state = ft_zero_state(&state);
	nb_line = 0;
	while ((ret_gnl = get_next_line(fd, &line)) == 1)
	{
		nb_line++;
		cursor = add_end_instruction(list_instr);
		cursor->nb_line = nb_line;
		check_commentchar(&line);
		if (state.name < 1 || state.comment < 1)
		{
			if (!parse_id(header, line, &state))
				return (false);
		}
		else
			parse_label(list_instr, cursor, line);
		printf("%zu : %s\n",cursor->nb_line , cursor->label);
	}
	return (true);
}
