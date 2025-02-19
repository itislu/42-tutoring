/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:51:55 by ldulling          #+#    #+#             */
/*   Updated: 2025/02/19 20:43:47 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

// utils
int		ft_atoi(const char *nptr);
bool	ft_isdigit(char c);
void	*ft_memset(void *s, int c, size_t n);
uint8_t	nbrlen(int nbr);
size_t	ft_strlen(const char *str);

// print
void	ft_putstr_fd(const char *str, int fd);

#endif
