/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:27:11 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/12 17:56:32 by alansiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# include <unistd.h>

int		ft_strlen(const char *s);
void	ft_putstr_fd(const char *s, int fd);
int		get_next_line(const int fd, char **line);
int		ft_strequ(char *s1, char *s2);
char	*ft_itoa_base(int value, int base);
void    *ft_memalloc(size_t size);
char    *ft_strrchr(const char *s, int c);

#endif
