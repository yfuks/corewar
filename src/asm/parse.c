/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:42:33 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/13 17:45:05 by alansiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
//#include "op.h"
#include "tools.h"

bool	parse(t_header *header, t_instruction *list_instr, int fd)
{
	int		ret_gnl;
	char	*line;

	header = NULL;
	list_instr = NULL;
	while ((ret_gnl = get_next_line(fd, &line)) == 1)
	{
		break ;
//		if (header->name_state < 1)
//			parse_id(header, line);
	}
	return (true);
}
