/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_fill_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:27:41 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/21 18:17:40 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>

extern t_op g_op_tab[17];

static bool	error_lab_instr(t_instruction **cursor, int n)
{
	ft_putstr_fd("line:", 2);
	ft_putnbr_fd((*cursor)->nb_line, 2);
	if (n == 1)
		ft_putstr_fd(" -> an argument is not good\n", 2);
	return (false);
}

/*
**verifie si les types des arguments correspondent
**bien a ce qui est donne dans op.c
*/

static bool	check_arg_type(t_instruction **cursor)
{
	int i;
	int good;

	i = 0;
	good = 0;
	while ((*cursor)->arg[i] && g_op_tab[(*cursor)->opcode - 1].args_types[i])
	{
		if ((*cursor)->arg_type[i] &
		g_op_tab[(*cursor)->opcode - 1].args_types[i])
			good++;
		i++;
	}
	if (good == i)
		return (true);
	return (false);
}

/*
** On comapre les premiers caractere de chaque arguemnts trouve, pour savoir
** de quels types d'arguemts il pourrait sagir
*/

bool		check_and_fill_arg(t_instruction **cursor)
{
	int i;

	i = 0;
	while ((*cursor)->arg[i])
	{
		if ((*cursor)->arg[i][0] == DIRECT_CHAR)
			(*cursor)->arg_type[i] = T_DIR;
		else if ((*cursor)->arg[i][0] == REG_CHAR)
			(*cursor)->arg_type[i] = T_REG;
		else if (ft_isdigit((*cursor)->arg[i][0]) || (*cursor)->arg[i][0] == LABEL_CHAR)
			(*cursor)->arg_type[i] = T_IND;
		else
			return (error_lab_instr(cursor, 1));
		i++;
	}
	if (!check_arg_type(cursor)) // || !fill_arg_value(cursor))
		return (false);
	return (true);
}