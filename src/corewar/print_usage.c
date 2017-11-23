/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:36:20 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/23 15:18:20 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

#define STD_ERR 2

int			print_usage(char *executable_name)
{
	ft_putstr_fd("Usage: ", STD_ERR);
	ft_putstr_fd(executable_name, STD_ERR);
	ft_putstr_fd(" [-dump N -v N -p] [[-n N] <champion.cor> ...]\n", STD_ERR);
	ft_putstr_fd("-dump N\t\t\t\t: Dumps memory after N cycles", STD_ERR);
	ft_putstr_fd(" then exits\n-n N <champion.cor>\t\t: Fix number", STD_ERR);
	ft_putstr_fd(" of the next champ (1-4)\n", STD_ERR);
	ft_putstr_fd("-v N\t\t\t\t: Verbosity levels, can be added ", STD_ERR);	
	ft_putstr_fd("together to enable several\n", STD_ERR);	
	ft_putstr_fd("\t\t\t\t  - 0 : Show only essentials\n", STD_ERR);	
	ft_putstr_fd("\t\t\t\t  - 1 : Show lives\n", STD_ERR);	
	ft_putstr_fd("\t\t\t\t  - 2 : Show cycles\n", STD_ERR);	
	ft_putstr_fd("\t\t\t\t  - 4 : Show operations ", STD_ERR);	
	ft_putstr_fd("(Params are NOT litteral ...)\n", STD_ERR);	
	ft_putstr_fd("-p\t\t\t\t: Output visual\n", STD_ERR);
	return (0);
}
