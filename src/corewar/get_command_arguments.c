
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

void        get_command_arguments(t_process *proc, t_arena *arena, int *index, int cmd)
{
    int   i;
    char  integer[4];
    char  tmp;
    char  encoding;

    i = 0;
    encoding = arena->arena[*index];
    while (i < op_tab[cmd].nb_arg)
    {
        ft_bzero(&integer, sizeof(char) * 4);
        tmp = encoding >> (6 - (i * 2));
        tmp = tmp & 0x3;
        if (tmp & T_REG)
        {
            *index = next_index(*index);
            proc->REG[i] = arena->arena[*index];
        }
        else if (tmp & T_DIR)
        {
          add_args_in_process(arena, index, 2, integer);
          proc->DIR[i] = ctos(integer);
        }
        else if (tmp & T_IND)
        {
            add_args_in_process(arena, index, IND_SIZE, integer);
            proc->IND[i] = ctos(integer);
        }
        i++;
    }
}
