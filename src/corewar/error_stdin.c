/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:46:49 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/10 18:51:38 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "tools.h"

bool	error_stdin(char **av, int ac)
{
	if (ac != 2)
	{
		ft_putstr("Error : number of file must be 1\n");
		return (false);
	}q
	return (true);
}
