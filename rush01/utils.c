#include "utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

// Modified atoi, returns -1 if nptr does not start with a number
int	ft_atoi(const char *nptr)
{
	int		n;
	bool	is_negative;

	n = 0;
	is_negative = false;
	if (*nptr == '-')
	{
		is_negative = true;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	if (!ft_isdigit(*nptr))
		return (-1);
	while (ft_isdigit(*nptr))
	{
		n = n * 10 + (*nptr - '0');
		nptr++;
	}
	if (is_negative)
		n = -n;
	return (n);
}

bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

uint8_t	nbrlen(int nbr)
{
	uint8_t	len;

	if (nbr == 0)
	{
		return (1);
	}
	len = (nbr < 0);
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

void	ft_putstr_fd(const char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

size_t	ft_strlen(const char *str) 
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

