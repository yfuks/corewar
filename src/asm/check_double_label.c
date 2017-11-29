/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_label.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:26:23 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/29 18:14:01 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tools.h"
#include <stdio.h>

bool	check_double_label(t_instruction **list_instr, char *label)
{
	t_instruction	*tmp;

	tmp = *list_instr;
	// ft_putstr_fd("check_double_label: ",1);
	// ft_putstr_fd(label,1);
	// ft_putstr_fd("\n",1);
	while (tmp && tmp->next)
	{
		// ft_putstr_fd("check_double_label while: ",1);
		// ft_putnbr_fd(tmp->nb_line,1);
		// ft_putstr_fd("\n",1);
		if (tmp->label)
		{
			// ft_putstr_fd("check_double_label tmp->label != NULL: ",1);
			// printf("%s",tmp->label);
			// ft_putstr_fd("\n",1);
		 	if (ft_strcmp(label, tmp->label) == 0)
				return (true);
		}
		// ft_putstr_fd("check_double_label while end: ",1);
		// ft_putnbr_fd(tmp->nb_line,1);
		// ft_putstr_fd("\n",1);
		tmp = tmp->next;
	}
	return (false);
}
