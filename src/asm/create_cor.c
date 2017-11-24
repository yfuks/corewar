/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:28:49 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/24 09:34:37 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"
#include <fcntl.h>

void	create_cor(t_instruction *list_instr, t_header *header, char *filename_s)
{
	int		fd;
	char	*filename_cor;
	t_instruction *tmp;
	// int i;

	tmp = list_instr;
	list_instr = NULL;
	header->magic = COREWAR_EXEC_MAGIC;
	if (!(filename_cor = ft_strnew(ft_strlen(filename_s) - 2)))
		return ;
	fd = open(ft_strcat(ft_strncpy(filename_cor, filename_s, ft_strlen(filename_s) - 2), ".cor"), O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	write(fd, header, sizeof(t_header));
	// while (tmp)
	// {
	// 	if (tmp->start_instr == 1)
	// 	{
	// 		write(fd, &(tmp->opcode), 1);
	// 		i = 0;
	// 		while (tmp->arg[i])
	// 		{
	// 			write(fd, &(tmp->arg_value[i]), 2);
	// 			i++;
	// 		}
	// 	}
// 		tmp = tmp->next;
// 	}
}
