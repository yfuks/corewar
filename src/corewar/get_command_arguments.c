
#include "corewar.h"
#include "tools.h"
#include <stdio.h>

t_op op_tab[17];

void       add_args_in_process(t_arena *arena, int *index, int size, char integer[4])
{
        int   j;

        j = 0;
        while (j < size)
        {
            *index = next_index(*index);
            integer[j] = arena->arena[*index];
            j++;
        }
}

static void	clean_proc(t_process *proc)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		proc->REG[i] = 0;
		proc->IND[i] = 0;
		proc->DIR[i] = 0;
		proc->args[i] = 0;
		i++;
	}
	proc->args[i] = 0;
}

static void	clean_integer(char integer[4])
{
	int		i;

	i = 0;
	while (i < 4)
	{
		integer[i] = 0;
		i++;
	}
}

void        get_command_arguments(t_process *proc, t_arena *arena, int *index, int cmd)
{
    int   i;
    char  integer[4];
    char  tmp;
    char  encoding;
    int   size_direct = 2;

    if (cmd == 0 || cmd == 1 || cmd == 5 || cmd == 6 || cmd == 7 || cmd == 12)
        size_direct = 4;
    i = 0;
    encoding = arena->arena[*index];
	clean_proc(proc);
    while (i < op_tab[cmd].nb_arg)
    {
		clean_integer(integer);
        tmp = encoding >> (6 - (i * 2));
        tmp = tmp & 0x3;
        if (tmp == IND_CODE)
        {
            add_args_in_process(arena, index, IND_SIZE, integer);
            proc->IND[i] = ctos(integer);
            proc->args[i] = T_IND;
        }
        else if (tmp == DIR_CODE)
        {
            add_args_in_process(arena, index, size_direct, integer);
            if (size_direct > 2)
                proc->DIR[i] = ctoi(integer);
            else
                proc->DIR[i] = ctos(integer);
                proc->args[i] = T_DIR;
        }
        else if (tmp == REG_CODE)
        {
			*index = next_index(*index);
            proc->REG[i] = arena->arena[*index];
            proc->args[i] = T_REG;
        }
        i++;
    }
    *index = next_index(*index);
}
