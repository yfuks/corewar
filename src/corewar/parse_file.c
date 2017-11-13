/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:33:28 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/13 14:28:57 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "corewar.h"
#include "op.h"
#include "tools.h"

#include <stdio.h>

#define BUFF_SIZE 1
#define STD_ERR 1

static t_champion	*print_cant_read_file(char *file)
{
	ft_putstr_fd("Can't read source file ", STD_ERR);
	ft_putstr_fd(file, STD_ERR);
	ft_putstr_fd("\n", STD_ERR);
	return (NULL);
}

static t_champion	*print_champ_too_large(char *file, int length)
{
	ft_putstr_fd("Error: File ", STD_ERR);
	ft_putstr_fd(file, STD_ERR);
	ft_putstr_fd(" has too large code (", STD_ERR);
	ft_putnbr_fd(length, STD_ERR);
	ft_putstr_fd(" bytes > ", STD_ERR);
	ft_putnbr_fd(CHAMP_MAX_SIZE, STD_ERR);
	ft_putstr_fd(" bytes)\n", STD_ERR);
	return (NULL);
}

t_champion			*parse_file(char *filename)
{
	int			fd;
	size_t		r;
	char		buff[BUFF_SIZE + 1];
	t_champion	*champion;
	int			i;
	int			prog_started;
	int			length;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (print_cant_read_file(filename));
	i = 0;
	prog_started = 0;
	length = 0;
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		i++;
		buff[r] = 0;
		if (!prog_started && i > PROG_NAME_LENGTH + COMMENT_LENGTH && buff[0])
			prog_started = 1;
		if (prog_started)
			length++;
//		printf("[%d %x] ", buff[0], buff[0]);
//		ft_putstr_fd(buff, 1);
	}
	if (length > CHAMP_MAX_SIZE)
		return (print_champ_too_large(filename, length));
	if (!(champion = new_champion("test", "test")))
		return (NULL);
	return (champion);
}
