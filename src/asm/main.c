/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:57:16 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/10 18:42:17 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"

int main(char **av, int ac)
{
	int				fd;
	t_id			*header;
	t_instruction	*list_instr;

	if (!error_stdin(av, ac))
		return (1);
	if(!(header = ft_memalloc(sizeof(t_id)))
		return (1);
	if(!(list_instr = ft_memalloc(sizeof(t_instruction))))
		return (1);
	if (!error_stdin(av, ac))
		return (1);
	if((fd = open(av[1], O_RDONLY)) == -1)
		return (1);
	if (!parse(header, list_instr, fd))
		return (1);
	if(close(fd) == -1)
		return (1);
	create_cor(list_instr, header);
	return (0);
}
