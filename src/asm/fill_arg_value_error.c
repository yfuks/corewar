/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arg_value_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:38:00 by jthillar          #+#    #+#             */
/*   Updated: 2017/12/01 13:55:08 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tools.h"

bool	error_fill_arg(int n, t_instruction **cursor)
{
	ft_putstr_fd("line : ", 2);
	ft_putnbr_fd((*cursor)->nb_line, 2);
	if (n == 1)
		ft_putstr_fd(" -> arg type\n", 2);
	if (n == 2)
		ft_putstr_fd(" -> reg value should be between 1 and 16\n", 2);
	if (n == 3)
		ft_putstr_fd(" -> label in instruction does not exists\n", 2);
	return (false);
}
