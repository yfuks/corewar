#include "tools.h"
#include "corewar.h"

#define CMD_LIVE_INDEX 0

#include <stdio.h>

static void     print_live(int champion_number, int value)
{
	print_process_number(champion_number);
    ft_putstr_fd(" | live ", STD_IN);
    ft_putnbr_fd(value, STD_IN);
    ft_putstr_fd("\n", STD_IN);
}

static void		print_said_alive(t_champion *champion)
{
	ft_putstr_fd("Player ", STD_IN);
	ft_putnbr_fd(champion->player_id, STD_IN);
	ft_putstr_fd(" (", STD_IN);
	ft_putstr_fd(champion->name, STD_IN);
	ft_putstr_fd(") is said to be alive\n", STD_IN);
}

void	   		cmd_live(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts)
{
	int		index;
	char	integer[4];
	int		count;
	int		player_nb;

	index = next_index(proc->index);
	ft_bzero(integer, sizeof(char) * 4);
	count = 0;
	while (count < 4)
	{
		integer[count] = arena->arena[index];
		index = next_index(index);
		count++;
	}
	player_nb = ctoi(integer);
	if (opts->verbose & SHOW_OPERATIONS)
		print_live(proc->number, player_nb);
	champion->last_live = arena->current_cycle;
	proc->last_live = arena->current_cycle;
	proc->live = 1;
	player_nb *= -1;
	if (player_nb <= arena->nb_champs && player_nb > 0)
	{
		if (opts->verbose & SHOW_LIVES)
			print_said_alive(&(arena->champions[player_nb - 1]));
		arena->lives[player_nb - 1] += 1;
		arena->last_live = player_nb;
	}
	proc->index = index;
}
