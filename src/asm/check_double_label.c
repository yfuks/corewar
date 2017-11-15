/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_label.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:26:23 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/15 15:01:37 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tools.h"

bool	check_double_label(t_instruction **list_instr, char *label)
{
	t_instruction *tmp;

	tmp = *list_instr;
	while (tmp && tmp->next)
	{
		// printf("%zu : %s\n", tmp->nb_line, tmp->label);
		if (tmp->label != NULL && ft_strcmp(label, tmp->label) == 0)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}
