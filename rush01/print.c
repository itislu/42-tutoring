/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:15:05 by ldulling          #+#    #+#             */
/*   Updated: 2025/02/19 20:32:59 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"
#include "utils.h"
#include <unistd.h>

void	print_grid(t_grid *grid)
{
	char	c;
	uint8_t	row;
	uint8_t	col;

	row = 0;
	while (row < grid->rows)
	{
		col = 0;
		while (col < grid->cols)
		{
			c = grid->cells[row][col] + '0';
			write(STDOUT_FILENO, &c, 1);
			col++;
			if (col < grid->cols)
			{
				write(STDOUT_FILENO, " ", 1);
			}
		}
		write(STDOUT_FILENO, "\n", 1);
		row++;
	}
}

void	ft_putstr_fd(const char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}
