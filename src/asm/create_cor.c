/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:28:49 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/21 14:40:49 by alansiva         ###   ########.fr       */
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

	list_instr = NULL;
	header->magic = COREWAR_EXEC_MAGIC;
	if (!(filename_cor = ft_strnew(ft_strlen(filename_s) - 2)))
		return ;
	fd = open(ft_strcat(ft_strncpy(filename_cor, filename_s, ft_strlen(filename_s) - 2), ".cor"), O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	write(fd, header, sizeof(t_header));
}
