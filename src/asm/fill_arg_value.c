/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arg_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:46:50 by jthillar          #+#    #+#             */
/*   Updated: 2017/12/04 16:54:11 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tools.h"

/*
** verifie si les labels dans les arguements correspondent
** aux label des instructions
*/

static bool	check_arg_label(t_instruction **list_instr,
t_instruction **cursor, int i, int n)
{
	t_instruction *tmp;

	tmp = *list_instr;
	while (tmp)
	{
		if (tmp->label && ft_strcmp((*cursor)->arg[i] + n, tmp->label) == 0)
		{
			(*cursor)->arg_value[i] = (tmp->cumul_byte_size -
			tmp->instr_byte_size) -
			((*cursor)->cumul_byte_size - (*cursor)->instr_byte_size);
			return (true);
		}
		tmp = tmp->next;
	}
	return (false);
}

static bool	reg_value(t_instruction **cursor, int i)
{
	if ((*cursor)->arg[i][1] == '\0' && !ft_isdigit((*cursor)->arg[i][1]))
		return (error_fill_arg(1, cursor));
	(*cursor)->arg_value[i] = ft_atoi((*cursor)->arg[i] + 1);
	if ((*cursor)->arg_value[i] > 16 || (*cursor)->arg_value[i] < 1)
		return (error_fill_arg(2, cursor));
	return (true);
}

static bool	dir_value(t_instruction **list_instr, t_instruction **cursor, int i)
{
	int j;

	if ((*cursor)->arg[i][1] && (*cursor)->arg[i][1] == LABEL_CHAR)
	{
		if (!(check_arg_label(list_instr, cursor, i, 2)))
			return (error_fill_arg(3, cursor));
	}
	else
	{
		if ((*cursor)->arg[i][1] != '-' && !ft_isdigit((*cursor)->arg[i][1]))
			return (error_fill_arg(1, cursor));
		j = 2;
		while ((*cursor)->arg[i][j])
		{
			if (!ft_isdigit((*cursor)->arg[i][j]))
				return (error_fill_arg(1, cursor));
			j++;
		}
		(*cursor)->arg_value[i] = ft_atoi((*cursor)->arg[i] + 1);
	}
	return (true);
}

static bool	ind_value(t_instruction **list_instr, t_instruction **cursor, int i)
{
	int j;

	if ((*cursor)->arg[i][0] && (*cursor)->arg[i][0] == LABEL_CHAR)
	{
		if (!(check_arg_label(list_instr, cursor, i, 1)))
			return (error_fill_arg(3, cursor));
	}
	else
	{
		if ((*cursor)->arg[i][0] != '-' && !ft_isdigit((*cursor)->arg[i][0]))
			return (error_fill_arg(1, cursor));
		j = 1;
		while ((*cursor)->arg[i][j])
		{
			if (!ft_isdigit((*cursor)->arg[i][j]))
				return (error_fill_arg(1, cursor));
			j++;
		}
		(*cursor)->arg_value[i] = ft_atoi((*cursor)->arg[i]);
	}
	return (true);
}

bool		fill_arg_value(t_instruction **list_instr, t_instruction **cursor)
{
	int i;

	i = 0;
	while ((*cursor)->arg[i])
	{
		if ((*cursor)->arg_type[i] == T_DIR)
		{
			if (!dir_value(list_instr, cursor, i))
				return (false);
		}
		else if ((*cursor)->arg_type[i] == T_IND)
		{
			if (!ind_value(list_instr, cursor, i))
				return (false);
		}
		else
		{
			if (!reg_value(cursor, i))
				return (false);
		}
		i++;
	}
	return (true);
}
