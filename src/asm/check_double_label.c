/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_label.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:26:23 by jthillar          #+#    #+#             */
/*   Updated: 2017/12/04 19:45:44 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tools.h"

bool	check_double_label(t_instruction **list_instr, char *label)
{
	t_instruction	*tmp;

	tmp = *list_instr;
	while (tmp->label && tmp->next)
	{
		if (tmp->label)
		{
			if (ft_strcmp(label, tmp->label) == 0)
				return (true);
		}
		tmp = tmp->next;
	}
	return (false);
}
