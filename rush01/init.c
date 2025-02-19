#include "grid.h"
#include "utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

static int	get_scale(const char *input);
static bool	set_requirements(t_grid *grid, const char *input);
static bool	set_requirement(uint8_t *requirement, uint8_t size, \
							const char *input, size_t *i);

bool	init_grid(t_grid *grid, const char *input)
{
	int	scale;

	ft_memset(grid, 0, sizeof(*grid));
	scale = get_scale(input);
	if (scale <= 0 || scale == MAX_SCALE)
		return (false);
	grid->rows = scale;
	grid->cols = scale;
	grid->cells = malloc(grid->rows * grid->cols);
	grid->top = malloc(grid->cols);
	grid->bottom = malloc(grid->cols);
	grid->left = malloc(grid->rows);
	grid->right = malloc(grid->rows);
	if (grid->cells == NULL || grid->top == NULL || grid->bottom == NULL 
		|| grid->left == NULL || grid->right == NULL)
	{
		clean_grid(grid);
		return (false);
	}
	if (!set_requirements(grid, input))
	{
		clean_grid(grid);
		return (false);
	}
	ft_memset(grid->cells, 0, grid->rows * grid->cols);
	return (true);
}

void	clean_grid(t_grid *grid)
{
	free(grid->cells);
	free(grid->top);
	free(grid->bottom);
	free(grid->left);
	free(grid->right);
	ft_memset(grid, 0, sizeof(*grid));
}

// Returns -1 if input is invalid
static int	get_scale(const char *input)
{
	int	spaces;

	spaces = 0;
	while (*input != '\0')
	{
		while (ft_isdigit(*input))
		{
			input++;
		}
		if (*input == ' ')
		{
			spaces++;
			input++;
		}
		else if (*input != '\0')
		{
			return (-1);
		}
	}
	if ((spaces + 1) % 4 != 0)
		return (-1);
	return ((spaces + 1) / 4);
}

static bool	set_requirements(t_grid *grid, const char *input)
{
	size_t	i;

	i = 0;
	if (!set_requirement(grid->top, grid->cols, input, &i)
		|| !set_requirement(grid->bottom, grid->cols, input, &i)
		|| !set_requirement(grid->left, grid->rows, input, &i)
		|| !set_requirement(grid->right, grid->rows, input, &i))
	{
		return (false);
	}
	return (true);
}

static bool	set_requirement(uint8_t *requirement, uint8_t size, \
							const char *input, size_t *i)
{
	int	amount;
	int	nbr;

	amount = 0;
	while (input[*i] != '\0' && amount < size)
	{
		nbr = ft_atoi(&input[*i]);
		if (nbr <= 0 || nbr > MAX_SCALE)
		{
			return (false);
		}
		requirement[amount] = (uint8_t)nbr;
		amount++;
		*i += nbrlen(nbr);
		if (input[*i] != '\0' && input[*i] != ' ')
		{
			return (false);
		}
		(*i)++;
	}
	return (amount == size);
}
