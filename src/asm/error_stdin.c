/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:39:17 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/13 14:00:47 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>

bool	error_stdin(char **av, int ac)
{
	char	*tmp;

	if (ac != 2)
	{
		if (ac == 1)
			ft_putstr_fd("Usage: ./asm [-a] <sourcefile.s>\n    -a : Instead \
of creating a .cor file, outputs a stripped and annotated version of the code \
to the standard output\n", 1);
		else
			ft_putstr_fd("Too many arguments\n    ex: ./asm <sourcefile.s>\n",
			1);
		return (false);
	}
	tmp = ft_strrchr(av[1], 's');
	if (*(tmp - 1) == '.' && *(tmp + 1) == '\0')
		return (true);
	else
	{
		ft_putstr_fd("Syntax error: source file must to be a .s\n    ex: \
./asm <sourcefile.s>\n", 1);
		return (false);
	}
}
