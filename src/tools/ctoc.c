/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctoc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:26:49 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/27 17:32:55 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		ctoc(char tab[1])
{
	char	value;

	value = (tab[0] & 0xFF);
	return (value);
}
