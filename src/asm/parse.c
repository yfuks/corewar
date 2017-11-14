/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:42:33 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/14 10:15:53 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
//#include "op.h"
#include "tools.h"
#include <stdio.h>

t_hstate	ft_zero_state(t_hstate *state)
{
	state->name = 0;
	state->comment = 0;

	return (*state);
}

bool	parse(t_header *header, t_instruction *list_instr, int fd)
{
	int		ret_gnl;
	char	*line;
	t_hstate	state;

	list_instr = NULL;
	state = ft_zero_state(&state);
	while ((ret_gnl = get_next_line(fd, &line)) == 1)
	{
		if (state.name < 1 || state.comment < 1)
			parse_id(header, line, &state);
		else
			break;
	}
	printf("%s\n", header->prog_name);
	printf("%s\n", header->comment);
	return (true);
}
