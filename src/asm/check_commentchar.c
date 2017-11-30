/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commentchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:24:42 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/30 11:37:07 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "asm.h"

void		check_commentchar(char *line)
{
	int i;

	i = 0;
	while ((line)[i])
	{
		if ((line)[i] == COMMENT_CHAR)
		{
			ft_bzero(line + i, ft_strlen(line + i));
			break ;
		}
		i++;
	}
}
