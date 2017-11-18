/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:02:23 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/16 17:02:25 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "corewar.h"

static void (*func[17])(t_process *proc, t_champion *champion, t_arena *arena) =
{
 	0, //cmd_live,
 	0, //cmd_ld,
 	0, //cmd_st,
 	0, //cmd_add,
 	0, //cmd_sub,
 	0, //cmd_and,
 	0, //cmd_or,
 	0, //cmd_xor,
 	0, //cmd_zjmp,
 	0, //cmd_ldi,
 	cmd_sti,
 	0, //cmd_fork,
 	0, //cmd_lld,
 	0, //cmd_lldi,
 	0, //cmd_lfork,
 	0, //cmd_aff
};

void		exec_command(t_process *proc, t_champion *champion, t_arena *arena)
{
	int		opcode;
	char  encoding;

	(void)champion;
	if (!(opcode = check_opcode(proc, arena)))
	{
		proc->index += 1;
		return ;
	}
	encoding = arena->arena[proc->index + 1];
	if (!is_valid_param(opcode, encoding))
	{
		proc->index += 1;
		return ;
	}
	func[opcode - 1](proc, champion, arena);
}
