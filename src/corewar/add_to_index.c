
#include "corewar.h"

int         add_to_index(int index, int nbr)
{
    int i;

    i = 0;
    while (i < nbr)
    {
        index = next_index(index);
        i++;
    }
    return (index);
}
