/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:15:35 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/29 14:59:15 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int		ft_realloc(char **rest)
{
	char	*tmp;

	if (!(tmp = ft_strnew(ft_strlen(*rest))))
		return (0);
	tmp = ft_strcpy(tmp, *rest);
	ft_memdel((void **)rest);
	if (!(*rest = ft_strnew(ft_strlen(tmp) + BUFF_SIZE)))
		return (0);
	*rest = ft_strcpy(*rest, tmp);
	ft_memdel((void **)&tmp);
	return (1);
}
