/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:36:20 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/13 13:54:53 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

#define STD_ERR 2

int			print_usage(char *executable_name)
{
	ft_putstr_fd("Usage: ", STD_ERR);
	ft_putstr_fd(executable_name, STD_ERR);
	ft_putstr_fd(" [-dump N -p] [[-n N] <champion.cor> ...]\n", STD_ERR);
	ft_putstr_fd("-dump N\t\t\t\t: Dumps memory after N cycles", STD_ERR);
	ft_putstr_fd(" then exits\n-n N <champion.cor>\t\t: Fix number", STD_ERR);
	ft_putstr_fd(" of the next champ (1-4)\n", STD_ERR);
	ft_putstr_fd("-p\t\t\t\t: Output visual\n", STD_ERR);
	return (0);
}
