/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:28:49 by alansiva          #+#    #+#             */
/*   Updated: 2017/12/04 19:45:28 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"
#include <fcntl.h>

static t_calc_bc	byte_code_bin(t_calc_bc *byco)
{
	while (byco->i < 3)
	{
		byco->byte_code = byco->byte_code << 2;
		byco->i++;
	}
	return (*byco);
}

static int			byte_code(t_instruction *tmp)
{
	t_calc_bc	byco;

	byco.i = 0;
	byco.byte_code = 0;
	if (tmp->opcode == 1 || tmp->opcode == 9 || tmp->opcode == 12
		|| tmp->opcode == 15)
		return (byco.byte_code);
	else
	{
		while (tmp->arg_type[byco.i] && byco.i < 3)
		{
			if (tmp->arg_type[byco.i] == 4)
				byco.byte_code += 3;
			else
				byco.byte_code += tmp->arg_type[byco.i];
			byco.byte_code = byco.byte_code << 2;
			byco.i++;
		}
		if (byco.i < 3)
			byco = byte_code_bin(&byco);
	}
	return (byco.byte_code);
}

static char			*file_newname(char *filename_cor, char *filename_s)
{
	filename_cor = ft_strsub(filename_s, 0, ft_strlen(filename_s) - 2);
	filename_cor = ft_strcat(filename_cor, ".cor");
	return (filename_cor);
}

static void			end_message_asm(char *filename_cor)
{
	ft_putstr_fd("Writing output program to ", 1);
	ft_putstr_fd(filename_cor, 1);
	ft_putstr_fd("\n", 1);
}

void				create_cor(t_instruction *list_instr, t_header *header,
char *filename_s)
{
	int				fd;
	char			*filename_cor;
	t_instruction	*tmp;
	int				bc;

	tmp = list_instr;
	filename_cor = NULL;
	filename_cor = file_newname(filename_cor, filename_s);
	fd = open(filename_cor, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	writing_header_fd(fd, header);
	while (tmp)
	{
		if (tmp->start_instr == 1)
		{
			write(fd, &(tmp->opcode), 1);
			bc = byte_code(tmp);
			if (bc != 0)
				write(fd, &(bc), 1);
			writing_prog_fd(fd, tmp);
		}
		tmp = tmp->next;
	}
	end_message_asm(filename_cor);
	ft_memdel((void**)&filename_cor);
}
