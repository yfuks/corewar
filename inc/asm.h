/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:58:27 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/07 19:15:03 by alansiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

typedef struct				s_id
{
	char					*name;
	char					*comment;
}							t_id;

typedef struct				s_instruction
{
	char					*label;
	char					*mnm;
	char					*reg_1;
	char					*reg_2;
	char					*reg_3;
	char					*dir_1;
	char					*dir_2;
	char					*dir_3;
	char					*ind_1;
	char					*ind_2;
	char					*ind_3;
	struct s_instruction	*next;
}							t_instruction;

/*
** PARSER ======================================================================
*/

bool	parse_id(t_id *id, char *line);

void	parse_instruction(t_instruction *new, char *line);
bool	parse_one_dir(t_instruction *new, char *line); // LIVE ZJMP FORK LFOR
bool	parse_log_op(t_instruction *new, char *line); // AND OR XOR
bool	parse_arith_op(t_instruction *new, char *line); // ADD SUB


int		get_next_line(const int fd, char **line);

/*
** =============================================================================
*/

#endif
