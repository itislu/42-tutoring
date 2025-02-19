/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:39:34 by ldulling          #+#    #+#             */
/*   Updated: 2025/02/19 20:39:35 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"
#include "utils.h"

static bool	set_requirement(uint8_t *requirement, uint8_t size, \
							const char *input, size_t *i);

// Returns -1 if input is invalid
int	get_scale(const char *input)
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

bool	set_requirements(t_grid *grid, const char *input)
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
