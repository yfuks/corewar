/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:58:27 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/15 12:16:20 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include "op.h"
# define SPACE	' '
# define TAB 	'\t'

typedef struct				s_hstate
{
	int						name;
	int						comment;
}							t_hstate;

typedef struct              s_label
{
    struct s_instruction    *label;
    struct s_label          *next;
}                           t_label;

typedef struct				s_instruction
{
	char					*label; // 1er read
	char					*mnm;
	int						state; // a 1 si un seul argument
	int						start_instr;
	char					reg[3];
	char					dir[3];
	char					ind[3];
	int						value;
    size_t                  nb_line;
	struct s_label          *instr_label;
    struct s_instruction	*next;
}							t_instruction;


/*
** PARSER ======================================================================
*/

bool	parse(t_header *header, t_instruction **list_instr, int fd, char *filename);
void	check_commentchar(char **line);
bool	check_namechar(char *line, int size); // verifie s'il n'y a pas un mauvais caractere dans le .nom ou .comment

bool	parse_id(t_header *id, char *line, t_hstate *state);

void	parse_label(t_instruction **list_instr, t_instruction *cursor,char *line);
bool	check_labelschar(char *line); // verifie que les nom de label soit valide
bool    check_double_label(t_instruction **list_instr, char *label);
//void    get_label(t_instruction *list_instr, char *line);

void	parse_instruction(t_instruction *list_instr, char *line);

bool	parse_one_dir(t_instruction *list_instr, char *line); // LIVE ZJMP FORK LFOR
bool	parse_log_op(t_instruction *list_instr, char *line); // AND OR XOR
bool	parse_arith_op(t_instruction *list_instr, char *line); // ADD SUB
bool	parse_ldi_lldi(t_instruction *list_instr, char *line); // LDI LLDI
bool	parse_ld_lld(t_instruction *list_instr, char *line); // LD LLD
bool	parse_aff(t_instruction *list_instr, char *line); // AFF
bool	parse_st(t_instruction *list_instr, char *line); // ST
bool	parse_sti(t_instruction *list_instr, char *line); // STI


// if (#) get next line

/*
** LIST FCT ====================================================================
*/

t_instruction	*add_end_instruction(t_instruction **list_instr);
t_instruction   *add_end_label(t_label *instr_label);

/*
** CONVERSION ==================================================================
*/

void	create_cor(t_instruction *list_instr, t_header *id);

void	fill_id_hex(t_header *id, int fd);

void 	fill_instruction_hex(t_instruction *list_instr, int fd);
void    get_bytecode(t_instruction *list_instr);
void    get_value_param(t_instruction *list_instr);

/*
** ERROR =======================================================================
*/

bool	error_stdin(char **av, int ac); // ac == 2, arg fini par .s

#endif
