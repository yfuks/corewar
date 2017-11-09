/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:57:38 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/07 15:57:46 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int main(int argc, char **argv)
{
	t_arena		arena;
	t_options	options;

	if (!parse_arguments(argc, argv, &arena, &options))
		print_usage();
	return (0);
}
