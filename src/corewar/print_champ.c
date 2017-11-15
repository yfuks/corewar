
#include "corewar.h"
#include "tools.h"

void		print_champ(t_champion *champion)
{
	ft_putstr_fd("======= CHAMP ======\nName: ", 1);
	ft_putstr_fd(champion->name, 1);
	ft_putstr_fd("\nDescription: ", 1);
	ft_putstr_fd(champion->description, 1);
	ft_putstr_fd("\nSize: ", 1);
	ft_putnbr_fd(champion->prog_size, 1);
	ft_putstr_fd(" bytes\nid: ", 1);
	ft_putnbr_fd(champion->player_id, 1);
	ft_putstr_fd("\n", 1);		
}