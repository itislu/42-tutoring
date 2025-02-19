/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:51:46 by ldulling          #+#    #+#             */
/*   Updated: 2025/02/19 20:42:51 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H

# include <stdbool.h>
# include <stdint.h>

# define MAX_SCALE	254	// UINT8_MAX - 2

typedef struct s_grid
{
	uint8_t	**cells;
	uint8_t	*_cells_mem;
	uint8_t	rows;
	uint8_t	cols;
	uint8_t	*top;
	uint8_t	*bottom;
	uint8_t	*left;
	uint8_t	*right;
}	t_grid;

// init
bool	init_grid(t_grid *grid, const char *input);
void	clean_grid(t_grid *grid);

// parse
int		get_scale(const char *input);
bool	set_requirements(t_grid *grid, const char *input);

// grid
bool	is_dup(t_grid *grid, uint8_t row, uint8_t col);
bool	is_valid_grid(t_grid *grid);

// print
void	print_grid(t_grid *grid);

// iterators
uint8_t	top_to_bottom(t_grid *grid, uint8_t col, int *cur);
uint8_t	bottom_to_top(t_grid *grid, uint8_t col, int *cur);
uint8_t	left_to_right(t_grid *grid, uint8_t row, int *cur);
uint8_t	right_to_left(t_grid *grid, uint8_t row, int *cur);

#endif
