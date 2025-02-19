/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:51:51 by ldulling          #+#    #+#             */
/*   Updated: 2025/02/19 20:33:15 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"
#include "utils.h"
#include <stdbool.h>
#include <unistd.h>
#include <sys/param.h>

static bool	solve(t_grid *grid, uint8_t row, uint8_t col);

int	main(int argc, char *argv[])
{
	t_grid	grid;

	if (argc != 2 || !init_grid(&grid, argv[1]))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}
	if (solve(&grid, 0, 0))
	{
		print_grid(&grid);
	}
	else
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
	}
	clean_grid(&grid);
}

static bool	solve(t_grid *grid, uint8_t row, uint8_t col)
{
	const uint8_t	max = MAX(grid->rows, grid->cols);
	uint8_t			num;
	uint8_t			next_row;
	uint8_t			next_col;

	if (row == grid->rows)
		return (is_valid_grid(grid));
	next_col = col + 1;
	next_row = row;
	if (next_col == grid->cols)
	{
		next_row++;
		next_col = 0;
	}
	num = 1;
	while (num <= max)
	{
		grid->cells[row][col] = num;
		if (!is_dup(grid, row, col) && solve(grid, next_row, next_col))
			return (true);
		grid->cells[row][col] = 0;
		num++;
	}
	return (false);
}
