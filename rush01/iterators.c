/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:51:50 by ldulling          #+#    #+#             */
/*   Updated: 2025/02/19 19:51:50 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

// Start with cur set to -1, valid while cur not -1
uint8_t	top_to_bottom(t_grid *grid, uint8_t col, int *cur)
{
	uint8_t	cell;

	if (*cur == -1)
	{
		*cur = 0;
	}
	cell = *get_cell(grid, *cur, col);
	*cur += 1;
	if (*cur == grid->rows)
	{
		*cur = -1;
	}
	return (cell);
}

// Start with cur set to -1, valid while cur not -1
uint8_t	bottom_to_top(t_grid *grid, uint8_t col, int *cur)
{
	uint8_t	cell;

	if (*cur == -1)
	{
		*cur = grid->rows - 1;
	}
	cell = *get_cell(grid, *cur, col);
	*cur -= 1;
	return (cell);
}

// Start with cur set to -1, valid while cur not -1
uint8_t	left_to_right(t_grid *grid, uint8_t row, int *cur)
{
	uint8_t	cell;

	if (*cur == -1)
	{
		*cur = 0;
	}
	cell = *get_cell(grid, row, *cur);
	*cur += 1;
	if (*cur == grid->cols)
	{
		*cur = -1;
	}
	return (cell);
}

// Start with cur set to -1, valid while cur not -1
uint8_t	right_to_left(t_grid *grid, uint8_t row, int *cur)
{
	uint8_t	cell;

	if (*cur == -1)
	{
		*cur = grid->cols - 1;
	}
	cell = *get_cell(grid, row, *cur);
	*cur -= 1;
	return (cell);
}
