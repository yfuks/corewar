/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:58:58 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/24 15:08:50 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"

typedef struct	s_process
{
	int					index;
	int					remaining_cycles;
	char				waiting;
	int					args[4];
	char				REG[3];
	int					DIR[3];
	int					IND[3];
	struct s_process	*next;
}				t_process;

typedef struct	s_champion
{
	char				*name;
	char				*description;
	char				code[CHAMP_MAX_SIZE + 1];
	int					last_live;
	unsigned int		prog_size;
	unsigned int		player_id;
	int					registers[REG_NUMBER];
	int					carry;
	int					is_dead;
	t_process			*process;
}				t_champion;

typedef struct	s_arena
{
	char				arena[MEM_SIZE];
	int					current_cycle;
	int					lives[MAX_PLAYERS];
	int					nb_champs;
	int					last_live;
	t_champion			champions[MAX_PLAYERS];
}				t_arena;

typedef	struct	s_options
{
	int			dump;
	char		print;
	int			verbose;
}				t_options;

# define SHOW_LIVES			1
# define SHOW_CYCLES		2
# define SHOW_OPERATIONS	4
# define SHOW_DEATHS		8

/*
**  AFFICHAGE
*/

void			print_map_arena(t_arena *arena);
void			print_arena(t_arena *arena);

/*
**	BATTLE
*/

int				next_index(int index);
int    			prev_index(int index);
int        		add_to_index(int index, int nbr);
void			check_process(t_arena *arena, t_options *opts);
int				check_opcode(t_process *proc, t_arena *arena);
void			exec_command(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts);
int				is_valid_param(int cmd_opcode, char encoding);
void       		get_command_arguments(t_process *proc, t_arena *arena, int *index, int cmd);

void			cmd_live(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts);
void			cmd_ld(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts);
void			cmd_st(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts);
void			cmd_add(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts);
void			cmd_sub(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts);
void			cmd_and(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts);
void			cmd_or(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts);
void			cmd_xor(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts);
void			cmd_zjmp(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts);
void			cmd_ldi(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts);
void			cmd_sti(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts);
void			cmd_fork(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts);
void			cmd_lld(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts);
void			cmd_lldi(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts);
void			cmd_lfork(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts);
void			cmd_aff(t_process *proc, t_champion *champion, t_arena *arena, t_options *opts);

/*
**	ARENA
*/

int				init_arena(t_arena *arena);
void			play(t_arena *arena, t_options *options);
int				check_deads(t_arena *arena, t_options *options, int cycle_to_die);

/*
**	TOOLS
*/

t_process		*new_process(int position);
void			add_process_to_champion(t_champion *champion, t_process *process);
int				parse_arguments(int ac, char **av, t_arena *arena, t_options *options);
int				parse_options(int *index, char **av, t_options *options);
t_champion		*new_champion(char *filename, t_header *header, int fd);
t_champion		*parse_champion(char *executable_name, int *index, char **av);
t_champion		*parse_file(char *filename);
int				add_champion_in_arena(t_champion *champion, t_arena *arena);
int				print_usage(char *executable_name);
void			print_champ(t_champion *champion);
void      		copy_int_to_arena(t_arena *arena, unsigned int value, int index);
int				get_memory(t_arena *arena, int index, int size);

#endif
