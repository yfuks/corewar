#include "corewar.h"
#include "tools.h"

#define CMD_ST_INDEX 2

t_op op_tab[17];

static void print_st_ind(int champion_number, int reg, int addr1) 
{
    ft_putstr_fd("P    ", STD_IN);
    ft_putnbr_fd(champion_number, STD_IN);
    ft_putstr_fd(" | st r", STD_IN);
    ft_putnbr_fd(reg, STD_IN);
    ft_putstr_fd(" ", STD_IN);
    ft_putnbr_fd(addr1, STD_IN);
    ft_putstr_fd("\n", STD_IN);
}


void	   		cmd_st(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts)
{
  int   index;
  int   index_tmp;
  int   args[2];

  index = next_index(proc->index);
  index_tmp = 0;
  get_command_arguments(proc, arena, &index, CMD_ST_INDEX);
  if (proc->REG[0] >= REG_NUMBER || !proc->REG[0] || proc->DIR[1] || proc->REG[1] >= REG_NUMBER)
    return ;
  args[0] = champion->registers[(int)proc->REG[0] - 1];
  if (proc->REG[1])
  {
  	champion->registers[(int)proc->REG[1] - 1] = args[0];
  }
  else if (proc->IND[1])
  {
  	index_tmp = add_to_index(proc->index, (proc->IND[1] % IDX_MOD));
  	copy_int_to_arena(arena, args[0], index_tmp);
  }
  if (opts->verbose & SHOW_OPERATIONS)
	  print_st_ind(champion->player_id, proc->REG[0], proc->IND[1]);
  proc->index = index;
}
