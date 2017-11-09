/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:58:27 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/09 18:39:13 by alansiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <stdlib.h>

typedef struct				s_id
{
	char					*name;
	char					*comment;
    size_t                  etat;
}							t_id;

typedef struct              s_label
{
    struct s_instruction    *label;
    struct s_label          *next;
}                           t_label;

typedef struct				s_instruction
{
	char					*label; // 1er read
	char					*mnm;
	int						etat; // a 1 si un seul argument
	char					*reg_1;
	char					*reg_2;
	char					*reg_3;
	char					*dir_1;
	char					*dir_2;
	char					*dir_3;
	char					*ind_1;
	char					*ind_2;
	char					*ind_3;
	int						value;
    size_t                  nb_line;
    struct s_label          *instr_label;
    struct s_instruction	*next;
}							t_instruction;


/*
** PARSER ======================================================================
*/

bool	parse_id(t_id *id, char *line);

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

void            *ft_memalloc(size_t size);
t_instruction   *ft_append_list(t_instruction *tmp);

/*
** CONVERSION ==================================================================
*/

void	create_cor(t_instruction *tmp, t_id *id);

void	fill_id_hex(t_id *id, int fd);

void 	fill_instruction_hex(t_instruction *tmp, int fd);
void    get_bytecode(t_instruction *tmp);
void    get_value_param(t_instruction *tmp);

/*
** ADDIOTIONALS FCT ============================================================
*/

int		get_next_line(const int fd, char **line);
int		ft_strequ(char *s1, char *s2);
char	*ft_itoa_base(intmax_t value, intmax_t base);

#endif
