/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:33:28 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/10 15:23:06 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "corewar.h"
#include "op.h"
#include "tools.h"

#include <stdio.h>

#define BUFF_SIZE 1

t_champion		*parse_file(char *filename)
{
	int			fd;
	size_t		r;
	char		buff[BUFF_SIZE + 1];
	t_champion	*champion;
//	int			i;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = 0;
		
		printf("[%d %x] ", buff[0], buff[0]);
//		ft_putstr_fd(buff, 1);
	}
	if (!(champion = new_champion("test", "test")))
		return (NULL);
	return (champion);
}
