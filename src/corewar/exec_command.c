/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:02:23 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/23 18:04:43 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "corewar.h"

t_op op_tab[17];

static void (*func[17])(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts) =
{
 	cmd_live,
 	cmd_ld,
 	cmd_st,
 	0, //cmd_add,
 	0, //cmd_sub,
 	cmd_and,
 	0, //cmd_or,
 	0, //cmd_xor,
 	cmd_zjmp,
 	0, //cmd_ldi,
 	cmd_sti,
 	0, //cmd_fork,
 	0, //cmd_lld,
 	0, //cmd_lldi,
 	0, //cmd_lfork,
 	0, //cmd_aff
};

void		exec_command(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts)
{
	//int        next_command_opcode;
	int			opcode;
	char		encoding;

	if (!(opcode = check_opcode(proc, arena)))
	{
		proc->index = next_index(proc->index);
		return ;
	}
	encoding = arena->arena[next_index(proc->index)];
	if (!is_valid_param(opcode, encoding))
	{
		proc->index = next_index(proc->index);
		return ;
	}
    if (func[opcode - 1])
        func[opcode - 1](proc, champion, arena, opts);
    proc->remaining_cycles = 1;
}
