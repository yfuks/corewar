/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:33:28 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/13 17:10:21 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "corewar.h"
#include "op.h"
#include "tools.h"

#include <stdio.h>

#define BUFF_SIZE 1
#define STD_ERR 2

static t_champion	*print_cant_read_file(char *file)
{
	ft_putstr_fd("Can't read source file ", STD_ERR);
	ft_putstr_fd(file, STD_ERR);
	ft_putstr_fd("\n", STD_ERR);
	return (NULL);
}

static t_champion	*print_champ_too_large(char *file, header_t *header)
{
	ft_putstr_fd("Error: File ", STD_ERR);
	ft_putstr_fd(file, STD_ERR);
	ft_putstr_fd(" has too large code (", STD_ERR);
	ft_putnbr_fd(header->prog_size, STD_ERR);
	ft_putstr_fd(" bytes > ", STD_ERR);
	ft_putnbr_fd(CHAMP_MAX_SIZE, STD_ERR);
	ft_putstr_fd(" bytes)\n", STD_ERR);
	free(header);
	return (NULL);
}

static t_champion	*print_invalid_header(char *file)
{
	ft_putstr_fd("Error: File ", STD_ERR);
	ft_putstr_fd(file, STD_ERR);
	ft_putstr_fd(" has an invalid header\n", STD_ERR);
	return (NULL);
}

static header_t		*read_champion_header(int fd)
{
	header_t	*header;

	if (!(header = (header_t *)malloc(sizeof(header_t))))
		return (NULL);
	ft_bzero(header, sizeof(header_t));
	read(fd, header, sizeof(header_t));
	header->magic = reverse_uint(header->magic);
	header->prog_size = reverse_uint(header->prog_size);
	return (header);
}

t_champion			*parse_file(char *filename)
{
	int			fd;
	t_champion	*champion;
	header_t	*header;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (print_cant_read_file(filename));
	if (!(header = read_champion_header(fd)))
		return (NULL);
	if (!header->prog_size || header->magic != COREWAR_EXEC_MAGIC)
		return (print_invalid_header(filename));
	if (header->prog_size > CHAMP_MAX_SIZE)
		return (print_champ_too_large(filename, header));
	if (!(champion = new_champion(filename, header, fd)))
	{
		free(header);
		return (NULL);
	}
	free(header);
	return (champion);
}
