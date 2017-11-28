/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_label.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:26:23 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/28 15:54:59 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tools.h"
#include <stdio.h>

bool	check_double_label(t_instruction **list_instr, char *label)
{
	t_instruction	*tmp;

	tmp = *list_instr;
	while (tmp->label && tmp->next)
	{
		if (tmp->label && label && !(ft_strcmp(label, tmp->label)))
			return (false);
		tmp = tmp->next;
	}
	ft_putstr_fd("la\n", 1);
	return (true);
}
