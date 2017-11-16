/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_fill_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:27:41 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/16 16:01:04 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>

extern t_op g_op_tab[17];

/*
**verifie si les labels dans les arguements correspondent aux label des instructions
*/

static bool	check_arg_label(t_instruction **list_instr, char *arg)
{
	t_instruction *tmp;

	tmp = *list_instr;
	arg = ft_strsub(arg, 1, ft_strlen(arg));
	while (tmp && tmp->next)
	{
		if (tmp->label != NULL && ft_strcmp(arg, tmp->label) == 0)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

/*
**verifie si les types des arguments correspondent bien a ce qui est donne dans op.c
*/

static bool	check_arg_type(char **arg, t_instruction **cursor)
{
	int i;
	int good;

	i = 0;
	good = 0;
	while (arg[i] && g_op_tab[(*cursor)->opcode - 1].args_types[i])
	{
		if ((*cursor)->arg_type[i] & g_op_tab[(*cursor)->opcode - 1].args_types[i])
			good++;
		i++;
	}
	if (good == i)
		return (true);
	return (false);
}

bool		check_and_fill_arg(t_instruction **list_instr, t_instruction **cursor, char **arg)
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
		{
			(*cursor)->arg_type[i] = T_IND;
			if (!check_arg_label(list_instr, arg[i]))
				return (false);
		}
		else
			return (false);
		i++;
	}
	if (!check_arg_type(arg, cursor))
		return (false);
	return (true);
}
