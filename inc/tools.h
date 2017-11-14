/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:27:11 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/14 08:30:14 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# define BUFF_SIZE 1
# include <unistd.h>
# include <stdlib.h>

void		ft_bzero(void *s, size_t n);
int			ft_strlen(const char *s);
void		ft_putstr_fd(const char *s, int fd);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isdigit(char c);
int			ft_isspace(char c);
int			ft_atoi(char *str);
long int	ft_atol(char *str);
char		*ft_strdup(const char *s1);
void		ft_bzero(void *s, size_t n);
char		*ft_itoa_base(int nb, int base);
int			get_next_line(const int fd, char **line);
int			ft_strequ(char *s1, char *s2);
void   		*ft_memalloc(size_t size);
void		ft_putnbr_fd(int n, int fd);
char		*ft_itoa(int n);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
char		*ft_strcpy(char *dest, const char *src);
void		ft_memdel(void **ap);
char		*ft_strchr(const char *s, int c);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		**ft_split_t_sp(const char *s, char c, char d);
char		*ft_strtrim(const char *s);

#endif
