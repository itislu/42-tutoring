#include "grid.h"
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

static uint8_t	count_visible(t_grid *grid, uint8_t which, \
	uint8_t (*next)(t_grid *grid, uint8_t which, int *cur));

uint8_t	*get_cell(t_grid *grid, uint8_t row, uint8_t col)
{
	return (&grid->cells[row * grid->cols + col]);
}

bool	is_valid(t_grid *grid, uint8_t row, uint8_t col)
{
	return (count_visible(grid, col, top_to_bottom) == grid->top[col]
			&& count_visible(grid, col, bottom_to_top) == grid->bottom[col]
			&& count_visible(grid, row, left_to_right) == grid->left[row]
			&& count_visible(grid, row, right_to_left) == grid->right[row]);
}

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
			c = *get_cell(grid, row, col) + '0';
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
