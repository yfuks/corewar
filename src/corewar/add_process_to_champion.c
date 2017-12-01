/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_process_to_champion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:29:13 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/28 16:28:33 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <unistd.h>

void	add_process_to_champion(t_champion *champion, t_process *process)
{
	if (!champion->process)
	{
		process->number = 1;
		champion->process = process;
		return ;
	}
	process->next = champion->process;
	process->number = champion->process->number + 1;
	champion->process = process;
}
