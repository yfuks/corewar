#include "tools.h"
#include "corewar.h"

#define CMD_LIVE_INDEX 0

#include <stdio.h>

static void     print_live(int champion_number, int value)
{
    ft_putstr_fd("P    ", STD_IN);
    ft_putnbr_fd(champion_number, STD_IN);
    ft_putstr_fd(" | live ", STD_IN);
    ft_putnbr_fd(value, STD_IN);
    ft_putstr_fd("\n", STD_IN);
}

void	   		cmd_live(t_process *proc, t_champion *champion, t_arena *arena)
{
  int   index;
  char  integer[4];
  int   count;

  index = next_index(proc->index);
  ft_bzero(integer, sizeof(char) * 4);
  count = 0;
  while (count < 4)
  {
      integer[count] = arena->arena[index];
      index = next_index(index);
      count++;
  }
  print_live(champion->player_id, ctoi(integer));
  proc->index = index;
}
