/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:57:16 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/05 11:28:29 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"
#include <fcntl.h>

static t_instruction	*list_remove_first(t_instruction *list)
{
	t_instruction	*first;
	int				i;

	i = 0;
	first = list;
	ft_memdel((void**)&first->label);
	ft_memdel((void**)&first->double_label);
	if (first->arg)
	{
		while (first->arg[i] && i < 3)
		{
			ft_memdel((void**)&first->arg[i]);
			i++;
		}
	}
	ft_memdel((void**)&first->arg);
	list = list->next;
	free(first);
	return (list);
}

static void				ft_free_list(t_instruction *list)
{
	while (list)
	{
		if (list)
		{
			list = list_remove_first(list);
		}
	}
}

static int				error_file(void)
{
	ft_putstr_fd("File doesn't exist.\n", 2);
	return (1);
}

int						main(int ac, char **av)
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
		return (error_file());
	if (!parse(header, &list_instr, fd))
	{
		ft_free_list(list_instr);
		ft_memdel((void**)&header);
		return (1);
	}
	create_cor(list_instr, header, av[1]);
	if (close(fd) == -1)
		return (1);
	ft_free_list(list_instr);
	ft_memdel((void**)&header);
	return (0);
}
