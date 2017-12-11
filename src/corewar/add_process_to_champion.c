/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_process_to_champion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:29:13 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/01 17:47:18 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <unistd.h>

void		add_process_to_champion(t_champion *champion, t_process *process)
{
	static int	process_number;

	process_number += 1;
	if (!champion->process)
	{
		process->number = process_number;
		champion->process = process;
		return ;
	}
	process->next = champion->process;
	process->number = process_number;
	champion->process = process;
}
