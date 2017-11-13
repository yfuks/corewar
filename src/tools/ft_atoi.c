/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:21:42 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/09 18:22:01 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int		ft_atoi(char *str)
{
	int			i;
	long		res;
	int			negatif;

	res = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		++i;
	negatif = str[i] == '-' ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] && ft_isdigit(str[i]))
	{
		res *= 10;
		res += negatif * (str[i] - '0');
		++i;
	}
	if (res > 2147483647 || res < -2147483648)
		res = 0;
	return (res);
}
