/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_labelschar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:27:23 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/30 11:38:12 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tools.h"

static bool	error_labelschar(void)
{
	ft_putstr_fd("Error : wrong label char\n", 2);
	return (false);
}

bool		check_labelschar(char *line)
{
	int i;
	int j;
	int compt;

	i = 0;
	while (line[i])
	{
		j = 0;
		compt = i;
		while (LABEL_CHARS[j])
		{
			if (line[i] == LABEL_CHARS[j])
				i++;
			j++;
		}
		if (i == compt)
			return (error_labelschar());
	}
	return (true);
}
