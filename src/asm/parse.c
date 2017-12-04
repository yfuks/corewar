/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:42:33 by alansiva          #+#    #+#             */
/*   Updated: 2017/12/04 19:27:41 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tools.h"

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

static int		prev_parse_laband_instr(t_instruction **list_instr,
	t_instruction *cursor, char *line, t_count *count)
{
	parse_label(list_instr, cursor, line);
	if (!(parse_instruction(cursor, line)))
		return (0);
	cursor->cumul_byte_size = count->cumul + cursor->instr_byte_size;
	count->cumul = cursor->cumul_byte_size;
	return (1);
}

static bool		parse_first_read(t_header *header, t_instruction **list_instr,
	int fd, t_hstate *state)
{
	char			*line;
	t_instruction	*cursor;
	t_count			count;

	ft_bzero(&count, sizeof(t_count));
	while ((count.ret_gnl = get_next_line(fd, &line)) == 1)
	{
		// line = ft_trim(line);
		// ft_putstr_fd(line,1);
        //
		// return (true);
		count.nb_line++;
		cursor = add_end_instruction(list_instr);
		cursor->nb_line = count.nb_line;
		check_commentchar(line);
		if (state->name < 1 || state->comment < 1)
		{
			if (!parse_id(header, line, state))
				return (false);
		}
		else if (!(prev_parse_laband_instr(list_instr, cursor, line, &count)))
			return (false);
		if (line)
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

static bool		parse_second_read(t_instruction **list_instr)
{
	t_instruction	*cursor;
	int				script;

	script = 0;
	cursor = *list_instr;
	while (cursor)
	{
		if (cursor->start_instr == 1)
		{
			script++;
			if (!(fill_arg_value(list_instr, &cursor)))
				return (false);
		}
		cursor = cursor->next;
	}
	if (script == 0)
	{
		ft_putstr_fd("File has just a header\n", 2);
		return (false);
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
