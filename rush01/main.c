#include "grid.h"
#include "utils.h"
#include <stdbool.h>
#include <unistd.h>
#include <sys/param.h>

void	fill_default(t_grid *grid);

int main(int argc, char *argv[])
{
	t_grid	grid;

	if (argc != 2 || !init_grid(&grid, argv[1]))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}
	fill_default(&grid);
	print_grid(&grid);
	clean_grid(&grid);
}

bool	solve(t_grid *grid)
{
	return (true);
}

void	fill_default(t_grid *grid)
{
	uint8_t	row;
	uint8_t	col;

	row = 0;
	while (row < grid->rows)
	{
		col = 0;
		while (col < grid->cols)
		{
			*get_cell(grid, row, col) = 
				(col + row) % MAX(grid->rows, grid->cols) + 1;
			col++;
		}
		row++;
	}
}
