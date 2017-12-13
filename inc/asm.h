/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:58:27 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/13 11:34:14 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <stdlib.h>
# include <stdbool.h>
# include "op.h"
# define SPACE	' '
# define TAB 	'\t'
# define SIGNE  '-'
# define REG_CHAR 'r'

typedef struct	s_count
{
	int						nb_line;
	int						cumul;
	int						ret_gnl;
}				t_count;

typedef struct	s_calc_bc
{
	int						byte_code;
	int						i;
}				t_calc_bc;

typedef struct	s_hstate
{
	int						name;
	int						comment;
}				t_hstate;

typedef struct	s_instruction
{
	char					*label;
	char					*double_label;
	int						opcode;
	int						state;
	int						start_instr;
	int						arg_type[3];
	int						arg_size[3];
	char					**arg;
	unsigned int			arg_value[3];
	int						instr_label[3];
	int						instr_byte_size;
	int						cumul_byte_size;
	size_t					nb_line;
	struct s_instruction	*next;
}				t_instruction;

/*
** PARSER ======================================================================
*/

bool			parse(t_header *header, t_instruction **list_instr, int fd);
void			check_commentchar(char *line);
bool			check_namechar(char *line, int size);
bool			parse_id(t_header *id, char *line, t_hstate *state);
bool			fill_id_name(t_header *header, char *line, t_hstate *state);
bool			fill_id_com(t_header *header, char *line, t_hstate *state);
void			parse_label(t_instruction **list_instr, t_instruction *cursor,
	char *line);
bool			check_labelschar(char *line);
bool			check_double_label(t_instruction **list_instr, char *label);
bool			parse_instruction(t_instruction *cursor, char *line);
bool			parse_mnemonique(t_instruction **cursor, char *line);
bool			parse_arguments(t_instruction **cursor, char *line);
bool			check_and_fill_arg(t_instruction **cursor);

bool			fill_arg_value(t_instruction **list_instr,
	t_instruction **cursor);
void			ft_count_bytes(t_instruction **cursor);

/*
** LIST FCT ====================================================================
*/

t_instruction	*add_end_instruction(t_instruction **list_instr);

/*
** CONVERSION ==================================================================
*/

void			create_cor(t_instruction *list_instr, t_header *id,
	char *filename_s);
void			fill_id_hex(t_header *id, int fd);
void			fill_instruction_hex(t_instruction *list_instr, int fd);
void			get_bytecode(t_instruction *list_instr);
void			get_value_param(t_instruction *list_instr);
uint16_t		swap_uint16(uint16_t val);
uint32_t		swap_uint32(uint32_t val);
void			writing_header_fd(int fd, t_header *header);
void			writing_prog_fd(int fd, t_instruction *tmp);

/*
** ERROR =======================================================================
*/

bool			error_stdin(char **av, int ac);
bool			error_fill_arg(int n, t_instruction **cursor);
bool			error_id(int n);
bool			error_eof(char *error);
#endif
