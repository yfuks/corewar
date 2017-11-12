/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:24:30 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/12 17:53:35 by alansiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <unistd.h>

char    *ft_strrchr(const char *s, int c)
{
    size_t  i;

    i = ft_strlen(s) + 1;
    while (i--)
    {
        if (s[i] == (char)c)
            return ((char *)s + i);
    }
    return (NULL);
}
