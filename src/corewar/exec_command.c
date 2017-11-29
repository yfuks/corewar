/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:02:23 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/29 19:36:55 by yfuks            ###   ########.fr       */
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
 	cmd_add,
 	cmd_sub,
 	cmd_and,
	cmd_or,
	cmd_xor,
 	cmd_zjmp,
 	cmd_ldi,
 	cmd_sti,
 	cmd_fork,
 	cmd_lld,
 	cmd_lldi,
 	cmd_lfork,
 	cmd_aff
};

void		exec_command(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts)
{
//	int			opcode;
//	char		encoding;
	int			init_index;

	init_index = proc->index;
/*	if (!(opcode = check_opcode(proc, arena)))
	{
		proc->index = next_index(proc->index);
		return ;
	}*/
//	encoding = arena->arena[next_index(proc->index)];
/*	if (!is_valid_param(proc->current_opcode, encoding))
	{
		proc->index = next_index(proc->index);
		proc->index = index_jump(proc->current_opcode, encoding, proc->index);
		if (opts->verbose & SHOW_PC_MOOV && proc->current_opcode != 9)
			print_pc_moove(arena, init_index, proc->index);
		proc->remaining_cycles = 1;
		return ;
		}*/
    if (func[proc->current_opcode - 1])
        func[proc->current_opcode - 1](proc, champion, arena, opts);
	if (opts->verbose & SHOW_PC_MOOV && proc->current_opcode != 9)
		print_pc_moove(arena, proc->index_opc, proc->index);
    proc->remaining_cycles = 1;
}
