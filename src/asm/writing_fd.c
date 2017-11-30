/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:18:49 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/30 11:49:47 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tools.h"

extern t_op g_op_tab[17];

void		writing_header_fd(int fd, t_header *header)
{
	header->magic = swap_uint32(COREWAR_EXEC_MAGIC);
	header->prog_size = swap_uint32(header->prog_size);
	write(fd, header, sizeof(t_header));
}

void		writing_prog_fd(int fd, t_instruction *tmp)
{
	int i;

	i = 0;
	while (tmp->arg[i] && i < 3)
	{
		if (tmp->arg_size[i] > 1 && tmp->arg_size[i] < 4)
			tmp->arg_value[i] = swap_uint16(tmp->arg_value[i]);
		if (tmp->arg_size[i] == 4)
			tmp->arg_value[i] = swap_uint32(tmp->arg_value[i]);
		write(fd, &(tmp->arg_value[i]), tmp->arg_size[i]);
		i++;
	}
}
