/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arg_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:46:50 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/20 17:31:55 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>

bool	error_fill_arg(int n)
{
	if (n == 1)
		ft_putstr_fd("Error arg type\n", 2);
	if (n == 2)
		ft_putstr_fd("Error : reg value should be under 17\n", 2);
	return (false);
}

bool	reg_value(t_instruction **cursor, int i)
{
	if ((*cursor)->arg[i][1] == '\0' && !ft_isdigit((*cursor)->arg[i][1]))
		return (error_fill_arg(1));
	(*cursor)->arg_value[i] = ft_atoi((*cursor)->arg[i] + 1);
	if ((*cursor)->arg_value[i] > 16)
		return (error_fill_arg(2));
	return (true);
}

bool	dir_value(t_instruction **cursor, int i)
{
	int j;

	if ((*cursor)->arg[i][1] != '-' && !ft_isdigit((*cursor)->arg[i][1]))
		return (error_fill_arg(1));
	j = 2;
	while ((*cursor)->arg[i][j])
	{
		if(!ft_isdigit((*cursor)->arg[i][j]))
			return (error_fill_arg(1));
		j++;
	}
	(*cursor)->arg_value[i] = ft_atoi((*cursor)->arg[i] + 1);
	return (true);
}

bool	ind_value(t_instruction **cursor, int i)
{
	int j;

	if ((*cursor)->arg[i][0] != '-' && !ft_isdigit((*cursor)->arg[i][0]))
		return (error_fill_arg(1));
	j = 1;
	while ((*cursor)->arg[i][j])
	{
		if(!ft_isdigit((*cursor)->arg[i][j]))
			return (error_fill_arg(1));
		j++;
	}
	(*cursor)->arg_value[i] = ft_atoi((*cursor)->arg[i]);
	return (true);
}

bool	fill_arg_value(t_instruction **cursor)
{
	int i;

	i = 0;
	while ((*cursor)->arg[i])
	{
		if ((*cursor)->arg_type[i] == T_DIR)
		{
			if (!dir_value(cursor, i))
				return (false);
		}
		else if ((*cursor)->arg_type[i] == T_IND)
		{
			if (!ind_value(cursor, i))
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
