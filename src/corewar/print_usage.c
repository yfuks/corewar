/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:36:20 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/11 18:01:13 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

#define STD_ERR 2

int			print_usage(char *executable_name)
{
	ft_putstr_fd("Usage: ", STD_ERR);
	ft_putstr_fd(executable_name, STD_ERR);
	ft_putstr_fd(" [-dump N -v N -p] [[-n N] <champion.cor> ...]\n", STD_ERR);
	ft_putstr_fd("    -a\t\t\t: Prints output from \"aff\"", STD_ERR);
	ft_putstr_fd("Default is to hide it)\n", STD_ERR);
	ft_putstr_fd("#### TEXT OUTPUT MODE ###########################", STD_ERR);
	ft_putstr_fd("###############################\n    -dump N\t\t:", STD_ERR);
	ft_putstr_fd(" Dumps memory after N cycles then exits\n    -n N", STD_ERR);
	ft_putstr_fd(" <champion.cor>\t: Fix number of the next champ (", STD_ERR);
	ft_putstr_fd("1-4)\n    -v N\t\t: Verbosity levels, can be adde", STD_ERR);
	ft_putstr_fd("d together to enable several\n", STD_ERR);
	ft_putstr_fd("\t\t\t\t  - 0 : Show only essentials\n", STD_ERR);
	ft_putstr_fd("\t\t\t\t  - 1 : Show lives\n", STD_ERR);
	ft_putstr_fd("\t\t\t\t  - 2 : Show cycles\n", STD_ERR);
	ft_putstr_fd("\t\t\t\t  - 4 : Show operations", STD_ERR);
	ft_putstr_fd(" (Params are NOT litteral ...)\n", STD_ERR);
	ft_putstr_fd("\t\t\t\t  - 8 : Show deaths\n", STD_ERR);
	ft_putstr_fd("\t\t\t\t  - 16 : Show PC movements ", STD_ERR);
	ft_putstr_fd("(Except for jumps)\n", STD_ERR);
	ft_putstr_fd("#### VISUAL OUTPUT MODE #########################", STD_ERR);
	ft_putstr_fd("###############################\n", STD_ERR);
	ft_putstr_fd("    -p\t\t\t: Output visual\n", STD_ERR);
	ft_putstr_fd("##################################################", STD_ERR);
	ft_putstr_fd("##############################\n", STD_ERR);
	return (0);
}
