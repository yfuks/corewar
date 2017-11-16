/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:02:01 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/16 13:57:32 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>
extern t_op g_op_tab[17];

static bool	error_arg(int i)
{
	if (i == 1)
		ft_putstr_fd("Error : wrong number arguments for this instruction\n", 2);
	if (i == 2)
		ft_putstr_fd("Error : wrong type of argument\n", 2);
	return (false);
}

static bool	check_arg(t_instruction **cursor, char **arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i][0] == DIRECT_CHAR)
			(*cursor)->arg_type[i] = T_DIR;
		else if (arg[i][0] == REG_CHAR)
			(*cursor)->arg_type[i] = T_REG;
		else if (ft_isdigit(arg[i][0]) || arg[i][0] == LABEL_CHAR)
			(*cursor)->arg_type[i] = T_IND;
		else
			return (false);
		i++;
	}
	
	return (true);
}

bool		parse_arguments(t_instruction **cursor, char **line)
{
	char	**arg;
	int 	nb_arg;

	nb_arg = 0;
	arg = ft_strsplit(*line, SEPARATOR_CHAR);
	while (arg[nb_arg])
	{
		if (!(check_arg(cursor, arg))) // or regarde si type d'arguments semble bo
			return (error_arg(2));
		nb_arg++;
	}
	if (nb_arg != g_op_tab[(*cursor)->opcode - 1].nb_arg) // on regarde si le nombre d'argument correspont au nombre d'arguments de l'instruction
		return (error_arg(1));
	// printf("nb_arg = %d // opcode - 1 = %d\n", nb_arg, g_op_tab[(*cursor)->opcode-1].op_code);
	// printf("opcode : %d - line : '%s'\n", (*cursor)->opcode, *line);
	return (true);
}
