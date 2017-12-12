/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:58:58 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/12 12:30:19 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"

typedef struct	s_process
{
	int					index;
	int					number;
	int					opcode;
	int					index_opc;
	int					remaining_cycles;
	char				waiting;
	int					cycle_opc;
	int					args[4];
	char				reg[3];
	int					dir[3];
	int					ind[3];
	char				live;
	int					last_live;
	char				is_dead;
	int					carry;
	char				just_nexted;
	int					registers[REG_NUMBER];
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
	int					nb_lives;
	char				should_check_deads;
	char				is_last_cycle;
	char				at_least_one_process_alive;
	t_champion			champions[MAX_PLAYERS];
}				t_arena;

typedef	struct	s_options
{
	int			dump;
	char		print;
	int			verbose;
	char		aff;
}				t_options;

typedef struct	s_get_arguments
{
	char		integer[4];
	char		encoding;
	int			size_direct;
	int			tmp;
	int			i;
}				t_get_arguments;

# define SHOW_LIVES			1
# define SHOW_CYCLES		2
# define SHOW_OPERATIONS	4
# define SHOW_DEATHS		8
# define SHOW_PC_MOOV		16

/*
**  AFFICHAGE
*/

void			print_map_arena(t_arena *arena);
void			print_arena(t_arena *arena);
void			print_pc_moove(t_arena *arena, int from, int to);
void			print_process_number(int number);
void			print_winner(t_arena *arena);

/*
**	BATTLE
*/

void			reset_process_lives(t_arena *arena);
void			check_process_deads(t_arena *arena, t_options *opts, int ctd);
int				next_index(int index);
int				prev_index(int index);
int				index_jump(int opcode, char encoding, int index);
int				add_to_index(int index, int nbr);
int				check_process(t_arena *arena, t_options *opts, int cycle_to_die,
							int print);
int				check_opcode(t_process *proc, t_arena *arena);
void			exec_command(t_process *proc, t_champion *champion,
							t_arena *arena, t_options *opts);
int				is_valid_param(int cmd_opcode, char encoding);
void			get_command_arguments(t_process *proc, t_arena *arena,
									int *index, int cmd);

void			cmd_live(t_process *proc, t_champion *champion, t_arena *arena,
						t_options *opts);
void			cmd_ld(t_process *proc, t_champion *champion, t_arena *arena,
					t_options *opts);
void			cmd_st(t_process *proc, t_champion *champion, t_arena *arena,
					t_options *opts);
void			cmd_add(t_process *proc, t_champion *champion, t_arena *arena,
						t_options *opts);
void			cmd_sub(t_process *proc, t_champion *champion, t_arena *arena,
						t_options *opts);
void			cmd_and(t_process *proc, t_champion *champion, t_arena *arena,
						t_options *opts);
void			cmd_or(t_process *proc, t_champion *champion, t_arena *arena,
					t_options *opts);
void			cmd_xor(t_process *proc, t_champion *champion, t_arena *arena,
						t_options *opts);
void			cmd_zjmp(t_process *proc, t_champion *champion, t_arena *arena,
						t_options *opts);
void			cmd_ldi(t_process *proc, t_champion *champion, t_arena *arena,
						t_options *opts);
void			cmd_sti(t_process *proc, t_champion *champion, t_arena *arena,
						t_options *opts);
void			cmd_fork(t_process *proc, t_champion *champion, t_arena *arena,
						t_options *opts);
void			cmd_lld(t_process *proc, t_champion *champion, t_arena *arena,
						t_options *opts);
void			cmd_lldi(t_process *proc, t_champion *champion, t_arena *arena,
						t_options *opts);
void			cmd_lfork(t_process *proc, t_champion *champion, t_arena *arena,
						t_options *opts);
void			cmd_aff(t_process *proc, t_champion *champion, t_arena *arena,
						t_options *opts);

/*
**	ARENA
*/

int				init_arena(t_arena *arena);
void			play(t_arena *arena, t_options *options);
int				check_deads(t_arena *arena);

/*
**	TOOLS
*/

void			free_arena(t_arena *arena);
int				modulo_idx_mod(int value);
t_process		*new_process(int position);
void			add_process_to_champion(t_champion *champion,
										t_process *process);
int				parse_arguments(int ac, char **av, t_arena *arena,
								t_options *options);
int				parse_options(int *index, char **av, t_options *options);
t_champion		*new_champion(char *filename, t_header *header, int fd);
t_champion		*parse_champion(char *executable_name, int *index, char **av);
t_champion		*parse_file(char *filename);
int				add_champion_in_arena(t_champion *champion, t_arena *arena);
int				print_usage(char *executable_name);
void			print_champ(t_champion *champion);
void			copy_int_to_arena(t_arena *arena, unsigned int value,
								int index);
int				get_memory(t_arena *arena, int index, int size);

#endif
