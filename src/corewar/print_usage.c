/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:36:20 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/09 17:48:32 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

#define STD_ERR 2
#define USAGE "Usage: corewar [-dump N -p] [[-n N] <champion.cor> ...]\n\
-dump N\t\t\t\t: Dumps memory after N cycles then exits\n\
-n N <champion.cor>\t\t: Fix number of the next champ\n\
-p\t\t\t\t: Output visual\n"

int			print_usage(void)
{
	ft_putstr_fd(USAGE, STD_ERR);
	return (1);
}
