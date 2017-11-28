/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:42:33 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/28 15:59:14 by jthillar         ###   ########.fr       */
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
		check_commentchar(line);
		if (state->name < 1 || state->comment < 1)
		{
			if (!parse_id(header, line, state))
				return (false);
		}
		else
		{
			// ft_putstr_fd("parse_first_read\n", 1);
			ft_putnbr_fd(s_label_char(line), 1);
			ft_putstr_fd("\n",1);
			if (s_label_char(line) > 0)
			{
				ft_putnbr_fd(s_label_char(line), 1);
				ft_putstr_fd("\n",1);
				// ft_putstr_fd("parse_first_read2\n", 1);
				if (!(parse_label(list_instr, cursor, line, s_label_char(line))))
				{
					// ft_putstr_fd("parse_first_read21\n", 1);
					return (false);
				}
			}
			ft_putstr_fd("parse_first_read3\n", 1);
			if (!(parse_instruction(cursor, line)))
				return (false);
			ft_putstr_fd("parse_first_read4\n", 1);
			cursor->cumul_byte_size = count.cumul + cursor->instr_byte_size;
			count.cumul = cursor->cumul_byte_size;
		}
		ft_memdel((void**)&line);
	}
	header->prog_size = count.cumul;
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

	cursor = *list_instr;
	while ((ret_gnl = get_next_line(fd, &line)) == 1)
	{
		if (cursor && cursor->start_instr == 0)
			cursor = cursor->next;
		else
		{
			check_commentchar(line);
			if (!(fill_arg_value(list_instr, &cursor)))
				return (false);
			if (cursor && cursor->next)
				cursor = cursor->next;
		}
		ft_memdel((void**)&line);
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
