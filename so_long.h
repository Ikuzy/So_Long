/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:27:02 by ozouine           #+#    #+#             */
/*   Updated: 2024/06/28 16:29:39 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "GNL/get_next_line.h"

char	**ft_free(char **s, int j);
char	**ft_split(char const *s, char c);
void	closenkill(char *str, int i);
void	line_len(char **map, size_t i);
void	check_borders(char **map, size_t i);

#endif