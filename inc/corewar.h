/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:58:58 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/13 17:41:39 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"

typedef struct	s_process
{
	void				*pc;
	int					remaining_cycles;
	struct s_process	*next;
}				t_process;

typedef struct	s_champion
{
	char				*name;
	char				*description;
	char				code[CHAMP_MAX_SIZE + 1];
	unsigned int		prog_size;
	int					player_id;
	int					registers[REG_NUMBER];
	int					carry;
	t_process			*process;
}				t_champion;

typedef struct	s_arena
{
	char				arena[MEM_SIZE];
	int					current_cycle;
	int					lives[MAX_PLAYERS];
	t_champion			champions[MAX_PLAYERS];
}				t_arena;

typedef	struct	s_options
{
	int			dump;
	char		print;
}				t_options;

/*
**  AFFICHAGE
*/

void			print_map_arena(t_arena *arena);
void			print_arena(t_arena *arena);

/*
**	BATTLE
*/

int				check_opcode(t_process **proc, t_champion *champion, t_arena *arena);
void			exec_command(t_process **proc, t_champion *champion, t_arena *arena);

void			cmd_live(t_process **proc, t_arena *arena);
void			cmd_ld(t_process **proc, t_champion *champion, t_arena *arena);
void			cmd_st(t_process **proc, t_champion *champion, t_arena *arena);
void			cmd_add(t_process **proc, t_champion *champion, t_arena *arena);
void			cmd_sub(t_process **proc, t_champion *champion, t_arena *arena);
void			cmd_and(t_process **proc, t_champion *champion, t_arena *arena);
void			cmd_or(t_process **proc, t_champion *champion, t_arena *arena);
void			cmd_xor(t_process **proc, t_champion *champion, t_arena *arena);
void			cmd_zjmp(t_process **proc, t_champion *champion, t_arena *arena);
void			cmd_ldi(t_process **proc, t_champion *champion, t_arena *arena);
void			cmd_sti(t_process **proc, t_champion *champion, t_arena *arena);
void			cmd_fork(t_process **proc, t_champion *champion, t_arena *arena);
void			cmd_lld(t_process **proc, t_champion *champion, t_arena *arena);
void			cmd_lldi(t_process **proc, t_champion *champion, t_arena *arena);
void			cmd_lfork(t_process **proc, t_champion *champion, t_arena *arena);
void			cmd_aff(t_process **proc, t_champion *champion, t_arena *arena);

/*
**	ARENA
*/

int				init_arena(t_arena *arena);
void			next_cycle(t_arena *arena);
void			check_deads(t_champion champions[MAX_PLAYERS]);

/*
**	TOOLS
*/

int				parse_arguments(int ac, char **av, t_arena *arena, t_options *options);
int				parse_options(int index, char **av, t_options *options);
t_champion		*new_champion(char *filename, header_t *header, int fd);
t_champion		*parse_champion(char *executable_name, int *index, char **av);
t_champion		*parse_file(char *filename);
int				add_champion_in_arena(t_champion *champion, t_arena *arena);
int				print_usage(char *executable_name);
void			print_champ(t_champion *champion);

#endif
