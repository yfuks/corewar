/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:39:17 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/12 18:18:30 by alansiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tools.h"
#include <unistd.h>

bool    error_stdin(char **av, int ac)
{
    char    *tmp;

    if (ac != 2)
    {
        if (ac == 1)
            write(1, "Usage: ./asm [-a] <sourcefile.s>\n    -a : Instead of creating a .cor file, outputs a stripped and annotated version of the code to the standard output\n", 151);
        else
            write(1, "Too many arguments\n    ex: ./asm <sourcefile.s>\n", 49);
        return (false);
    }
    tmp = ft_strrchr(av[1], 's');
    if (*(tmp - 1) == '.' && *(tmp + 1) == '\0')
        return (true);
    else
    {
        write(1, "Syntax error: source file must to be a .s\n\tex: ./asm <sourcefile.s>", 68);
        return (false);
    }
}
