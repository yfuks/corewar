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

// static void (*func[17])(t_process *proc, t_champion *champion, t_arena *arena) =
// {
// 	cmd_live,
// 	cmd_ld,
// 	cmd_st,
// 	cmd_add,
// 	cmd_sub,
// 	cmd_and,
// 	cmd_or,
// 	cmd_xor,
// 	cmd_zjmp,
// 	cmd_ldi,
// 	cmd_sti,
// 	cmd_fork,
// 	cmd_lld,
// 	cmd_lldi,
// 	cmd_lfork,
// 	cmd_aff
// };

//static void (*func[17])(t_process *proc, t_champion *champion, t_arena *arena) = 
//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void		exec_command(t_process *proc, t_champion *champion, t_arena *arena)
{
	int		opcode;

	(void)champion;
	if (!(opcode = check_opcode(proc, arena)))
	{
		proc->index += 1;
		return ;
	}
	ft_putstr_fd("\nopcode: ", 1);
	ft_putnbr_fd(opcode, 1);
	ft_putstr_fd("\n", 1);
	//func[opcode - 1](proc, champion, arena);
}