/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:58:27 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/13 17:42:31 by alansiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include "op.h"

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

bool	parse(t_header *id, t_instruction *tmp, int fd);

bool	parse_id(t_header *id, char *line);

void	parse_label(t_instruction *tmp, char *line);
void    check_double_label(t_instruction *tmp, char *line);
void    get_label(t_instruction *tmp, char *line);

void	parse_instruction(t_instruction *tmp, char *line);

bool	parse_one_dir(t_instruction *tmp, char *line); // LIVE ZJMP FORK LFOR
bool	parse_log_op(t_instruction *tmp, char *line); // AND OR XOR
bool	parse_arith_op(t_instruction *tmp, char *line); // ADD SUB
bool	parse_ldi_lldi(t_instruction *tmp, char *line); // LDI LLDI
bool	parse_ld_lld(t_instruction *tmp, char *line); // LD LLD
bool	parse_aff(t_instruction *tmp, char *line); // AFF
bool	parse_st(t_instruction *tmp, char *line); // ST
bool	parse_sti(t_instruction *tmp, char *line); // STI


// if (#) get next line

/*
** LIST FCT ====================================================================
*/

t_instruction   *add_end_instruction(t_instruction *tmp);
t_instruction   *add_end_label(t_label *instr_label);

/*
** CONVERSION ==================================================================
*/

void	create_cor(t_instruction *tmp, t_header *id);

void	fill_id_hex(t_header *id, int fd);

void 	fill_instruction_hex(t_instruction *tmp, int fd);
void    get_bytecode(t_instruction *tmp);
void    get_value_param(t_instruction *tmp);

/*
** ERROR =======================================================================
*/

bool	error_stdin(char **av, int ac); // ac == 2, arg fini par .s

#endif
