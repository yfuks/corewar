/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:57:16 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/16 15:09:11 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"
#include <fcntl.h>

int     main(int ac, char **av)
{
	int				fd;
	t_header		*header;
	t_instruction	*list_instr;

	if (!error_stdin(av, ac))
		return (1);
	if (!(header = ft_memalloc(sizeof(t_header))))
		return (1);
	list_instr = NULL;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (1);
	if (!parse(header, &list_instr, fd, av[1]))
		return (1);
	exit(1);
	if (close(fd) == -1)
		return (1);
	create_cor(list_instr, header);
	return (0);
}
