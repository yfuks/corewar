/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_process_to_champion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:29:13 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/15 16:48:49 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <unistd.h>

void	add_process_to_champion(t_champion *champion, t_process *process)
{
	if (!champion->process)
	{
		champion->process = process;
		return ;
	}
	process->next = champion->process;
	champion->process = process;
}
