/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:02:01 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/21 18:17:36 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>

extern t_op g_op_tab[17];

bool	error_arg(int i, t_instruction **cursor)
{
	ft_putnbr_fd((*cursor)->nb_line, 2);
	if (i == 1)
		ft_putstr_fd(" -> Error : wrong nbr arguments\n", 2);
	if (i == 2)
		ft_putstr_fd(" -> Error : wrong type of argument\n", 2);
	return (false);
}

/*
** - On regarde si le nombre d'argument correspont au nombre d'arguments
** de l'instruction
** - On regarde si les type d'arguments sont les bons selon l'instruction
** - On compte le nombre d'octets par instruction;
** - On compte le cumul total d'octets des instruction;
*/

bool	parse_arguments(t_instruction **cursor,	char *line)
{
	int		nb_arg;

	nb_arg = 0;
	(*cursor)->arg = ft_strsplit(line, SEPARATOR_CHAR);
	while ((*cursor)->arg[nb_arg])
	{
		(*cursor)->arg[nb_arg] = ft_strtrim((*cursor)->arg[nb_arg]);
		nb_arg++;
	}
	if (nb_arg != g_op_tab[(*cursor)->opcode - 1].nb_arg)
		return (error_arg(1, cursor));
	if (!(check_and_fill_arg(cursor)))
		return (false);
	ft_count_bytes(cursor);
	return (true);
}
