/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:58:58 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/07 15:59:29 by yfuks            ###   ########.fr       */
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
	int			nbr_champ[MAX_PLAYERS];
	char		print;	
}				t_options;

/*
**  AFFICHAGE
*/

void			print_arena(t_arena *arena);

/*
**	BATTLE
*/

int				check_opcode(t_process **proc, t_champion *champion, t_arena *arena);
void			exec_command(t_process **proc, t_champion *champion, t_arena *arena);

void			live(t_process **proc, t_arena *arena);
void			ld(t_process **proc, t_champion *champion, t_arena *arena);
void			st(t_process **proc, t_champion *champion, t_arena *arena);
void			add(t_process **proc, t_champion *champion, t_arena *arena);
void			sub(t_process **proc, t_champion *champion, t_arena *arena);
void			and(t_process **proc, t_champion *champion, t_arena *arena);
void			or(t_process **proc, t_champion *champion, t_arena *arena);
void			xor(t_process **proc, t_champion *champion, t_arena *arena);
void			zjmp(t_process **proc, t_champion *champion, t_arena *arena);
void			ldi(t_process **proc, t_champion *champion, t_arena *arena);
void			sti(t_process **proc, t_champion *champion, t_arena *arena);
void			fork(t_process **proc, t_champion *champion, t_arena *arena);
void			lld(t_process **proc, t_champion *champion, t_arena *arena);
void			lldi(t_process **proc, t_champion *champion, t_arena *arena);
void			lfork(t_process **proc, t_champion *champion, t_arena *arena);
void			aff(t_process **proc, t_champion *champion, t_arena *arena);

/*
**	ARENA
*/

void			next_cycle(t_arena *arena);
void			check_deads(t_champion champions[MAX_PLAYERS]);

/*
**	TOOLS
*/

int				parse_arguments(int ac, char **av, t_arena *arena, t_options *options);
int				parse_options(int index, char **av, t_options *options);
t_arena			*new_arena(void);
t_champion		*new_champion(char *name, char *description);
t_champion		*parse_champion(int index, char **av, t_arena *arena);
void			add_champion_in_arena(t_champion *champion, t_arena *arena);
int				print_usage(void);

#endif
