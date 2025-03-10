/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:51:44 by ldulling          #+#    #+#             */
/*   Updated: 2025/02/19 20:40:40 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

static uint8_t	count_visible(t_grid *grid, uint8_t which, \
					uint8_t (*next)(t_grid *grid, uint8_t which, int *cur));
static bool		is_valid_row(t_grid *grid, uint8_t row);
static bool		is_valid_col(t_grid *grid, uint8_t col);

bool	is_dup(t_grid *grid, uint8_t row, uint8_t col)
{
	uint8_t	cell;
	uint8_t	i;
	int		cur;

	i = 0;
	cur = row;
	cell = top_to_bottom(grid, col, &cur);
	while (++i < grid->rows)
	{
		if (top_to_bottom(grid, col, &cur) == cell)
		{
			return (true);
		}
	}
	i = 0;
	cur = col;
	cell = left_to_right(grid, row, &cur);
	while (++i < grid->cols)
	{
		if (left_to_right(grid, row, &cur) == cell)
		{
			return (true);
		}
	}
	return (false);
}

bool	is_valid_grid(t_grid *grid)
{
	uint8_t	cur;

	cur = 0;
	while (cur < grid->rows)
	{
		if (!is_valid_row(grid, cur))
		{
			return (false);
		}
		cur++;
	}
	cur = 0;
	while (cur < grid->cols)
	{
		if (!is_valid_col(grid, cur))
		{
			return (false);
		}
		cur++;
	}
	return (true);
}

static bool	is_valid_row(t_grid *grid, uint8_t row)
{
	return (count_visible(grid, row, left_to_right) == grid->left[row]
		&& count_visible(grid, row, right_to_left) == grid->right[row]);
}

static bool	is_valid_col(t_grid *grid, uint8_t col)
{
	return (count_visible(grid, col, top_to_bottom) == grid->top[col]
		&& count_visible(grid, col, bottom_to_top) == grid->bottom[col]);
}

static uint8_t	count_visible(t_grid *grid, uint8_t which, \
					uint8_t (*next)(t_grid *grid, uint8_t which, int *cur))
{
	uint8_t	max;
	uint8_t	tmp;
	uint8_t	visible;
	int		cur;

	cur = -1;
	max = next(grid, which, &cur);
	visible = 1;
	while (cur != -1)
	{
		tmp = next(grid, which, &cur);
		if (tmp > max)
		{
			visible++;
			max = tmp;
		}
	}
	return (visible);
}
