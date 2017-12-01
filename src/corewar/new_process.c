/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:24:59 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/15 16:49:32 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tools.h"
#include "corewar.h"

t_process	*new_process(int position)
{
	t_process	*process;

	if (!(process = (t_process *)malloc(sizeof(t_process))))
		return (NULL);
	ft_bzero(process, sizeof(t_process));
	process->next = NULL;
	process->index = position;
	return (process);
}
