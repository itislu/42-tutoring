/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:13:23 by ldulling          #+#    #+#             */
/*   Updated: 2025/02/11 12:12:18 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#ifndef WIDTH
# define WIDTH				5
#endif
#ifndef HEIGHT
# define HEIGHT				5
#endif

#ifndef MAX_DISPLAY_WIDTH
# define MAX_DISPLAY_WIDTH	2147483647
#endif
#ifndef MAX_DISPLAY_HEIGHT
# define MAX_DISPLAY_HEIGHT	2147483647
#endif

#define USAGE_ERROR			1
#define POSITIVE_ONLY		"Width and height have to be positive numbers.\n"

#define TOP_LEFT			0
#define TOP_RIGHT			1
#define BOTTOM_LEFT			2
#define BOTTOM_RIGHT		3
#define HORIZONTAL			4
#define VERTICAL			5
#define MIDDLE				6

static const char	*g_chars;

void				ft_putchar(char c);
const char			*assign_chars_compile_time(void);
static const char	*assign_chars_run_time(int rush_number);
static bool			rush(int width, int height);
static void			print_row(int width, char left, char middle, char right);
static int			ft_atoi(const char *nptr);

int	main(int argc, char *argv[])
{
	int	width;
	int	height;

	width = WIDTH;
	height = HEIGHT;
	if (argc > 1)
		width = ft_atoi(argv[1]);
	if (argc > 2)
		height = ft_atoi(argv[2]);
	if (argc > 3)
		g_chars = assign_chars_run_time(ft_atoi(argv[3]));
	else
		g_chars = assign_chars_compile_time();
	if (!rush(width, height))
	{
		write(STDERR_FILENO, POSITIVE_ONLY, sizeof(POSITIVE_ONLY));
		return (USAGE_ERROR);
	}
}

const char	*assign_chars_run_time(int rush_number)
{
	if (rush_number == 0)
		return ("oooo-| ");
	if (rush_number == 1)
		return ("/\\\\/** ");
	if (rush_number == 2)
		return ("AACCBB ");
	if (rush_number == 3)
		return ("ACACBB ");
	if (rush_number == 4)
		return ("ACCABB ");
	return ("oooo-| ");
}

bool	rush(int width, int height)
{
	if (height < 0 || width < 0)
		return (false);
	if (0 < height && height <= MAX_DISPLAY_HEIGHT)
	{
		print_row(width,
			g_chars[TOP_LEFT], g_chars[HORIZONTAL], g_chars[TOP_RIGHT]);
		height--;
	}
	else if (height > 0)
	{
		print_row(width, '.', '.', '.');
		print_row(width, '.', '.', '.');
		height = MAX_DISPLAY_HEIGHT;
	}
	while (height > 1)
	{
		print_row(width, g_chars[VERTICAL], g_chars[MIDDLE], g_chars[VERTICAL]);
		height--;
	}
	if (height > 0)
		print_row(width,
			g_chars[BOTTOM_LEFT], g_chars[HORIZONTAL], g_chars[BOTTOM_RIGHT]);
	return (true);
}

void	print_row(int width, char left, char middle, char right)
{
	if (width == 0)
	{
		ft_putchar('\n');
		return ;
	}
	if (width <= MAX_DISPLAY_WIDTH)
	{
		ft_putchar(left);
		width--;
	}
	else
	{
		write(STDOUT_FILENO, "...", 3);
		width = MAX_DISPLAY_WIDTH;
	}
	while (width > 1)
	{
		ft_putchar(middle);
		width--;
	}
	if (width > 0)
		ft_putchar(right);
	ft_putchar('\n');
}

// Modified atoi, returns -1 for any unexpected character.
int	ft_atoi(const char *nptr)
{
	int		n;
	bool	is_negative;

	n = 0;
	is_negative = false;
	if (*nptr == '-')
	{
		is_negative = true;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = n * 10 + (*nptr - '0');
		nptr++;
	}
	if (*nptr != '\0')
		return (-1);
	if (is_negative)
		n = -n;
	return (n);
}
