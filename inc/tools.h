
#ifndef TOOLS_H
# define TOOLS_H

#include <stdlib.h>

int			ft_strlen(const char *s);
void		ft_putstr_fd(const char *s, int fd);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isdigit(char c);
int			ft_isspace(char c);
int			ft_atoi(char *str);
long int	ft_atol(char *str);
char		*ft_strdup(const char *s1);
void		ft_bzero(void *s, size_t n);

#endif
