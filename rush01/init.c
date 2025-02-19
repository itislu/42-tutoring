/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:51:48 by ldulling          #+#    #+#             */
/*   Updated: 2025/02/19 20:39:24 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"
#include "utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

static void	set_cells_mem(t_grid *grid);

bool	init_grid(t_grid *grid, const char *input)
{
	int	scale;

	ft_memset(grid, 0, sizeof(*grid));
	scale = get_scale(input);
	if (scale <= 0 || scale == MAX_SCALE)
		return (false);
	grid->rows = scale;
	grid->cols = scale;
	grid->_cells_mem = malloc(grid->rows * grid->cols);
	grid->cells = malloc(grid->rows * sizeof(*grid->cells));
	grid->top = malloc(grid->cols);
	grid->bottom = malloc(grid->cols);
	grid->left = malloc(grid->rows);
	grid->right = malloc(grid->rows);
	if (grid->_cells_mem == NULL || grid->cells == NULL || grid->top == NULL
		|| grid->bottom == NULL || grid->left == NULL || grid->right == NULL)
		return (clean_grid(grid), false);
	if (!set_requirements(grid, input))
		return (clean_grid(grid), false);
	ft_memset(grid->_cells_mem, 0, grid->rows * grid->cols);
	set_cells_mem(grid);
	return (true);
}

void	clean_grid(t_grid *grid)
{
	free(grid->cells);
	free(grid->_cells_mem);
	free(grid->top);
	free(grid->bottom);
	free(grid->left);
	free(grid->right);
	ft_memset(grid, 0, sizeof(*grid));
}

static void	set_cells_mem(t_grid *grid)
{
	uint8_t	i;

	i = 0;
	while (i < grid->rows)
	{
		grid->cells[i] = &grid->_cells_mem[grid->cols * i];
		i++;
	}
}
