#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

int		ft_atoi(const char *nptr);
bool	ft_isdigit(char c);
void	*ft_memset(void *s, int c, size_t n);
uint8_t	nbrlen(int nbr);
void	ft_putstr_fd(const char *str, int fd);
size_t	ft_strlen(const char *str) ;

#endif
