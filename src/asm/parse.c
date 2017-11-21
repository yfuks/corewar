/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:42:33 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/21 18:17:24 by jthillar         ###   ########.fr       */
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
	int				nb_line;
	int 			cumul;

	cumul = 0;
	nb_line = 0;
	while ((ret_gnl = get_next_line(fd, &line)) == 1)
	{
		nb_line++;
		cursor = add_end_instruction(list_instr);
		cursor->nb_line = nb_line;
		check_commentchar(line);
		if (state->name < 1 || state->comment < 1)
		{
			if (!parse_id(header, line, state))
				return (false);
		}
		else
		{
			parse_label(list_instr, cursor, line);
			if (!(parse_instruction(cursor, line)))
				return (false);
			cursor->cumul_byte_size = cumul + cursor->instr_byte_size;
			cumul = cursor->cumul_byte_size;
		}
	}
	header->prog_size = cumul + PROG_NAME_LENGTH + COMMENT_LENGTH;
	return (true);
}

/*
** Second read pour le parsing et la recuperation des instruction et arguments
** - on avance dans la liste chaine pour etre sur les maillons qui correspont
** à l'apres header
** - on suprime ce qui est a gauche du COMMENTCHAR s'il y en a un
*/

static bool		parse_second_read(t_instruction **list_instr, int fd)
{
	char			*line;
	t_instruction	*cursor;
	int				ret_gnl;
	// int 			cumul;
	int i;

	cursor = *list_instr;
	// cumul = 0;
	while ((ret_gnl = get_next_line(fd, &line)) == 1)
	{
		if (cursor && cursor->start_instr == 0)
			cursor = cursor->next;
		else
		{
			check_commentchar(line);
			// cursor->cumul_byte_size = cumul + cursor->instr_byte_size;
			if(!(fill_arg_value(list_instr, &cursor)))
				return (false);
			i = 0;
			while (cursor->arg[i])
			{
				printf("line : %zu -> %s,%d,%d size : %d - %d\n",cursor->nb_line, cursor->arg[i], cursor->arg_type[i], cursor->arg_value[i], cursor->instr_byte_size, cursor->cumul_byte_size);
				i++;
			}
			// cumul = cursor->cumul_byte_size;
			if (cursor && cursor->next)
				cursor = cursor->next;
		}
	}
	return (true);
}

/*
** On separe le parsing en deux pour les deux read
*/

bool			parse(t_header *header, t_instruction **list_instr, int fd,
	char *filename)
{
	t_hstate	state;

	state = ft_zero_state(&state);
	if (!(parse_first_read(header, list_instr, fd, &state)))
		return (false);
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (false);
	if (!(parse_second_read(list_instr, fd)))
		return (false);
	return (true);
}
