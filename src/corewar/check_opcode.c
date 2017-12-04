/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opcode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:28:06 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/16 17:28:08 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

t_op op_tab[17];

int			check_opcode(t_process *proc, t_arena *arena)
{
	int		i;

	i = 0;
	while (op_tab[i].op_code != arena->arena[proc->index] && i < 17)
		i++;
	if (i >= 17)
		return (0);
	if (proc->index_opc == 0)
		proc->remaining_cycles = 1;
	else
		proc->remaining_cycles = 2;
	return (op_tab[i].op_code);
}
