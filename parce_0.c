/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:27:27 by ozouine           #+#    #+#             */
/*   Updated: 2024/06/28 16:35:55 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	closenkill(char *str, int i)
{
	printf("%s\n", str);
	exit(i);
}

void	line_len(char **map, size_t i)
{
	size_t j;
	size_t len;

	j = 0;
	len = ft_strlen(map[0]);
	while (j < i)
	{
		if (ft_strlen(map[j]) != len)
			closenkill("lines lenght doesn't match", 1);
		j++;
	}
	if (len == i)
		closenkill("Square Map", 1);
		
}

void	check_borders(char **map, size_t i)
{
	size_t	j;
	
	j = 0;
	while (map[0][j] && map[i - 1][j])
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			closenkill("Invalid Map Border", 1);
		j++;
	}
	j = 0;
	while (j < i)
	{
		if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1')
			closenkill("Invalid Map Border", 1);
		j++;
	}
}
