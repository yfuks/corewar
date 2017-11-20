
#include "corewar.h"
#include "tools.h"
#include <stdio.h>

void        split_int_in_char(char integer[4], unsigned int value)
{
    integer[3] = value & 0xFF;
    integer[2] = (value >> 8) & 0xFF;
    integer[1] = (value >> 16) & 0xFF;
    integer[0] = (value >> 24) & 0xFF;
}

void        copy_int_to_arena(t_arena *arena, unsigned int value, int index)
{
    int     i;
    char    integer[4];

    i = 0;
    ft_bzero(integer, sizeof(char) * 4);
    split_int_in_char(integer, value);
    while (i < 4)
    {
        arena->arena[index] = integer[i];
        index = next_index(index);
        i++;
    }
}
