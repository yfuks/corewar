/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_champion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:58:41 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/15 15:27:58 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "corewar.h"
#include "tools.h"

#define STD_ERR 2

static int		print_wrong_size(char *filename, t_champion *champion, int size)
{
	ft_putstr_fd("Error: File ", STD_ERR);
	ft_putstr_fd(filename, STD_ERR);
	ft_putstr_fd(" size in header (", STD_ERR);
	ft_putnbr_fd(champion->prog_size, STD_ERR);
	ft_putstr_fd(") don't match code size (", STD_ERR);	
	ft_putnbr_fd(size, STD_ERR);
	ft_putstr_fd(")\n", STD_ERR);
	return (0);
}	

static int		print_cant_read_code(char *filename)
{
	ft_putstr_fd("Error: File ", STD_ERR);
	ft_putstr_fd(filename, STD_ERR);
	ft_putstr_fd(" can't read code after header\n", STD_ERR);
	return (0);
}

static int		read_code(char *filename, t_champion *champion, int fd)
{
	unsigned int	r;
	char			buff[CHAMP_MAX_SIZE + 1];

	if ((r = read(fd, buff, CHAMP_MAX_SIZE)) <= 0)
		return (print_cant_read_code(filename));
	if (r != champion->prog_size)
		return (print_wrong_size(filename, champion, r));
	ft_memcpy(champion->code, buff, r);
	return (1);
}

t_champion      *new_champion(char *filename, t_header *header, int fd)
{
	t_champion	*champion;

	if (!(champion = (t_champion *)malloc(sizeof(t_champion))))
		return (NULL);
	ft_bzero(champion, sizeof(t_champion));
	champion->prog_size = header->prog_size;
	if (!(champion->name = ft_strdup(header->prog_name)))
	{
		free(champion);
		return (NULL);
	}
	if (!(champion->description = ft_strdup(header->comment)))
	{
		free(champion);
		return (NULL);
	}
	if (!read_code(filename, champion, fd))
	{
		free(champion);
		return (NULL);
	}
	return (champion);
}
