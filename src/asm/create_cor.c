/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:28:49 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/27 13:51:34 by alansiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"
#include <fcntl.h>
#include <stdint.h>

extern t_op g_op_tab[17];

uint16_t swap_uint16( uint16_t val )
{
    return (val << 8) | (val >> 8);
}

uint32_t swap_uint32( uint32_t val )
{
    val = ((val << 8) & 0xFF00FF00 ) | ((val >> 8) & 0xFF00FF );
    return (val << 16) | (val >> 16);
}

int byte_code(t_instruction *tmp)
{
	int byte_code;
	int i;

	i = 0;
	byte_code = 0;
	if (tmp->opcode == 1 || tmp->opcode == 9 || tmp->opcode == 12
		|| tmp->opcode == 15 || tmp->opcode == 16)
		return (byte_code);
	else
	{
		while (tmp->arg_type[i] && i < 3)
		{
			if (tmp->arg_type[i] == 4)
				byte_code += 3;
			else
				byte_code += tmp->arg_type[i];
			byte_code = byte_code << 2;
			i++;
		}
		if (i < 3)
		{
			while (i < 3)
			{
				byte_code = byte_code << 2;
				i++;
			}
		}
	}
	return (byte_code);
}

#include <stdio.h>

void	create_cor(t_instruction *list_instr, t_header *header, char *filename_s)
{
	int		fd;
	char	*filename_cor;
	t_instruction *tmp;
	int i;
	int bc;

	printf("cumul_byte_size: %d\n", list_instr->instr_byte_size);
	printf("prog_size: %d\n", header->prog_size);
	tmp = list_instr;
	list_instr = NULL;
	header->magic = swap_uint32(COREWAR_EXEC_MAGIC);
	header->prog_size = swap_uint32(header->prog_size);
	if (!(filename_cor = ft_strnew(2)))
		return ;
	filename_cor = ft_strcpy(filename_cor, "./");
	filename_cor = ft_strcat(ft_strncpy(filename_cor, filename_s, ft_strlen(filename_s) - 2), ".cor");
	fd = open(filename_cor, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	write(fd, header, sizeof(t_header));
	while (tmp)
	{
		if (tmp->start_instr == 1)
		{
			write(fd, &(tmp->opcode), 1);
			bc = byte_code(tmp);
			if (bc != 0)
				write(fd, &(bc), 1);
			i = 0;
			while (tmp->arg[i] && i < 3)
			{
				if (tmp->arg_size[i] > 1 && tmp->arg_size[i] < 4)
					tmp->arg_value[i] = swap_uint16(tmp->arg_value[i]);
				if (tmp->arg_size[i] == 4)
					tmp->arg_value[i] = swap_uint32(tmp->arg_value[i]);
				write(fd, &(tmp->arg_value[i]), tmp->arg_size[i]);
				printf("arg_value: %d\n", tmp->arg_value[i]);
				printf("arg_size:  %d\n", tmp->arg_size[i]);
				printf("----\n");
				i++;
			}
			// write(fd, &(tmp->opcode), 1);
		}
		printf("++++\n");
		tmp = tmp->next;
	}
}


// void	create_cor(t_instruction *list_instr, t_header *header, char *filename_s)
// {
// 	int		fd;
// 	char	*filename_cor;
// 	t_instruction *tmp;
// 	int i;
//
// 	tmp = list_instr;
// 	list_instr = NULL;
// 	header->magic = COREWAR_EXEC_MAGIC;
// 	if (!(filename_cor = ft_strnew(ft_strlen(filename_s) - 2)))
// 		return ;
// 	fd = open(ft_strcat(ft_strncpy(filename_cor, filename_s, ft_strlen(filename_s) - 2), ".cor"), O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
// 	write(fd, header, sizeof(t_header));
// }
