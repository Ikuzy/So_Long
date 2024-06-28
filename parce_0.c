/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:27:27 by ozouine           #+#    #+#             */
/*   Updated: 2024/06/28 18:03:37 by ozouine          ###   ########.fr       */
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
	if (len == 0)
		closenkill("Empty Map File", 1);
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
	while (map[j] && j < i)
	{
		if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1')
			closenkill("Invalid Map Border", 1);
		j++;
	}
}

void	check_comp(char **map, size_t i)
{
	size_t	len;
	size_t	j;
	size_t	c;
	
	len = ft_strlen(map[0]);
	j = 0;
	while (j < i)
	{
		c = 0;
		while (c < len)
		{
			if (map[j][c] != '1' && map[j][c] != '0' && map[j][c] != 'P' && map[j][c] != 'E' && map[j][c] != 'C' )
				closenkill("Invalid Character", 1);
			c++;
		}
		j++;
	}
}

void	count_comp(char **map, size_t i)
{
	size_t	j;
	size_t	c;
	size_t	len;
	size_t	P_count;
	size_t	E_count;

	len = ft_strlen(map[0]);
	j = 0;
	P_count = 0;
	E_count = 0;
	while (j < i)
	{
		c = 0;
		while (c < len)
		{
			if (map[j][c] == 'P')
				P_count++;
			else if (map[j][c] == 'E')
				E_count++;
			if (P_count > 1 || E_count > 1)
				closenkill("There is Multiple players And/Or Exits", 1);
			c++;
		}
		j++;
	}
}
