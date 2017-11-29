/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:42:33 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/29 19:27:11 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"
#include <fcntl.h>
#include <stdio.h>

/*
**	On met les variable d'etat du header a zero
*/

static t_hstate	ft_zero_state(t_hstate *state)
{
	state->name = 0;
	state->comment = 0;
	return (*state);
}

/*
** Premier read du fichier source : Pour recuperer le header et les label
** des instructions
** - on ajoute un nouveau maillon
** - on lui donne le numero de la igne du fichier source lue
** - on suprime ce qui est a gauche du COMMENTCHAR s'il y en a un
** - on parse et recupere les donnee du header
** - on parse et reupere les labels
** - on parse et ajoute les donnes des instruction
*/

static bool		parse_first_read(t_header *header, t_instruction **list_instr,
	int fd, t_hstate *state)
{
	char			*line;
	t_instruction	*cursor;
	int				ret_gnl;
	t_count			count;

	count.cumul = 0;
	count.nb_line = 0;
	while ((ret_gnl = get_next_line(fd, &line)) == 1)
	{
		count.nb_line++;
		cursor = add_end_instruction(list_instr);
		cursor->nb_line = count.nb_line;
		// ft_putnbr_fd(cursor->nb_line,1);
		// ft_putstr_fd(" first read : ",1);
		// ft_putstr_fd(line,1);
		// ft_putstr_fd("\n",1);
		// cursor->label = NULL;
		// cursor->double_label = NULL;
		check_commentchar(line);
		if (state->name < 1 || state->comment < 1)
		{
			if (!parse_id(header, line, state))
				return (false);
		}
		else
		{
			// ft_putstr_fd("first read before label: ",1);
			// ft_putstr_fd(line,1);
			// ft_putstr_fd("\n",1);
			parse_label(list_instr, cursor, line);
			// ft_putstr_fd("first read before instruction: ",1);
			// ft_putstr_fd(line,1);
			// ft_putstr_fd("\n",1);
			if (!(parse_instruction(cursor, line)))
				return (false);
			// ft_putstr_fd("first read after instruction: ",1);
			// ft_putstr_fd(line,1);
			// ft_putstr_fd("\n",1);
			cursor->cumul_byte_size = count.cumul + cursor->instr_byte_size;
			count.cumul = cursor->cumul_byte_size;
		}
		if (line)
			ft_memdel((void**)&line);
	}
	// ft_putstr_fd("sakut\n", 1);
	header->prog_size = count.cumul;
	return (true);
}

/*
** Second read pour le parsing et la recuperation des instruction et arguments
** - on avance dans la liste chaine pour etre sur les maillons qui correspont
** à l'apres header
** - on suprime ce qui est a gauche du COMMENTCHAR s'il y en a un
*/

static bool		parse_second_read(t_instruction **list_instr)
{
	t_instruction	*cursor;

	cursor = *list_instr;
	while (cursor && cursor->next)
	{
		if (cursor->start_instr == 0)
			cursor = cursor->next;
		else
		{
			if (!(fill_arg_value(list_instr, &cursor)))
				return (false);
			if (cursor && cursor->next)
				cursor = cursor->next;
		}
	}
	return (true);
}

/*
** On separe le parsing en deux pour les deux read
*/

bool			parse(t_header *header, t_instruction **list_instr, int fd)
{
	t_hstate	state;

	state = ft_zero_state(&state);
	if (!(parse_first_read(header, list_instr, fd, &state)))
		return (false);
	if (!(parse_second_read(list_instr)))
		return (false);
	return (true);
}
