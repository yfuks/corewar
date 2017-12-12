/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:46:08 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/12 17:38:55 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"
#include <stdio.h>

t_op	g_op_tab[17];

static void	add_args_in_process(t_arena *arena, int *index, int size,
							char integer[4])
{
	int		j;

	j = 0;
	while (j < size)
	{
		*index = next_index(*index);
		integer[j] = arena->arena[*index];
		j++;
	}
}

static void	resets_args(t_process *proc)
{
	ft_bzero(proc->args, sizeof(int) * 4);
	ft_bzero(proc->reg, sizeof(int) * 3);
	ft_bzero(proc->ind, sizeof(int) * 3);
	ft_bzero(proc->dir, sizeof(int) * 3);
}

static void	put_args(t_get_arguments *args, t_process *proc, t_arena *arena,
					int *index)
{
	if (args->tmp == IND_CODE)
	{
		add_args_in_process(arena, index, IND_SIZE, args->integer);
		proc->ind[args->i] = ctos(args->integer);
		proc->args[args->i] = T_IND;
	}
	else if (args->tmp == DIR_CODE)
	{
		add_args_in_process(arena, index, args->size_direct, args->integer);
		if (args->size_direct > 2)
			proc->dir[args->i] = ctoi(args->integer);
		else
			proc->dir[args->i] = ctos(args->integer);
		proc->args[args->i] = T_DIR;
	}
	else if (args->tmp == REG_CODE)
	{
		*index = next_index(*index);
		proc->reg[args->i] = arena->arena[*index];
		proc->args[args->i] = T_REG;
	}
}

void		get_command_arguments(t_process *proc, t_arena *arena, int *index,
							int cmd)
{
	t_get_arguments	args;

	args.size_direct = 2;
	if (cmd == 0 || cmd == 1 || cmd == 5 || cmd == 6 || cmd == 7 || cmd == 12)
		args.size_direct = 4;
	args.i = 0;
	args.encoding = arena->arena[*index];
	resets_args(proc);
	while (args.i < g_op_tab[cmd].nb_arg)
	{
		ft_bzero(&(args.integer), sizeof(char) * 4);
		args.tmp = (args.encoding) >> (6 - (args.i * 2));
		args.tmp = (args.tmp) & 0x3;
		put_args(&args, proc, arena, index);
		args.i += 1;
	}
	*index = next_index(*index);
}
