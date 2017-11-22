
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
    int   size_direct = 2;

    size_direct = (cmd == 0 || cmd == 1 || cmd == 5 || cmd == 6 || cmd == 7 || cmd == 12) ? 4 : 2;
    i = 0;
    encoding = arena->arena[*index];
    ft_bzero(proc->args, sizeof(int) * 4);
    while (i < op_tab[cmd].nb_arg)
    {
        ft_bzero(&integer, sizeof(char) * 4);
        tmp = encoding >> (6 - (i * 2));
        tmp = tmp & 0x3;
        if (tmp & T_REG)
        {
            *index = next_index(*index);
            proc->REG[i] = arena->arena[*index];
            proc->args[i] = T_REG;
        }
        else if (tmp & T_DIR)
        {
          add_args_in_process(arena, index, size_direct, integer);
          proc->DIR[i] = ctos(integer);
          proc->args[i] = T_DIR;
        }
        else if (tmp & T_IND)
        {
            add_args_in_process(arena, index, IND_SIZE, integer);
            proc->IND[i] = ctos(integer);
            proc->args[i] = T_IND;
        }
        i++;
    }
    *index = next_index(*index);
}
