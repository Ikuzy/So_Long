/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:27:27 by ozouine           #+#    #+#             */
/*   Updated: 2024/07/04 20:41:13 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	closenkill(t_mlx *lbx, char *str, int i)
{
	printf("%s\n", str);
	if (lbx->map != NULL || lbx->map_dup != NULL)
	{
		ft_free(lbx->map);
		ft_free(lbx->map_dup);
	}
	exit(i);
}

void	line_len(t_mlx *lbx, char **map, int i)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(map[0]);
	if (len == 0 || map[0] == NULL)
		closenkill(lbx, "Empty Map File", 1);
	while (j < i)
	{
		if (ft_strlen(map[j]) != len)
			closenkill(lbx, "Invalid Map", 1);
		j++;
	}
	if (len == i)
		closenkill(lbx, "Invalid Map", 1);
}

void	check_borders(t_mlx *lbx, char **map, int i)
{
	int	j;

	j = 0;
	while (map[0][j] && map[i - 1][j])
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			closenkill(lbx, "Invalid Map", 1);
		j++;
	}
	j = 0;
	while (map[j] && j < i)
	{
		if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1')
			closenkill(lbx, "Invalid Map", 1);
		j++;
	}
}

void	check_comp(t_mlx *lbx, char **map, int i)
{
	int	len;
	int	j;
	int	c;

	len = ft_strlen(map[0]);
	j = 0;
	while (j < i)
	{
		c = 0;
		while (c < len)
		{
			if (map[j][c] != '1' && map[j][c] != '0' && map[j][c] != 'P' &&
				map[j][c] != 'E' && map[j][c] != 'C' )
				closenkill(lbx, "Invalid Character", 1);
			c++;
		}
		j++;
	}
}

void	count_comp(t_mlx *lbx, char **map, int i)
{
	t_var	v;

	v.len = ft_strlen(map[0]);
	v.j = 0;
	v.p_count = 0;
	v.e_count = 0;
	v.c_count = 0;
	while (v.j < i)
	{
		v.c = 0;
		while (v.c < v.len)
		{
			if (map[v.j][v.c] == 'P')
				v.p_count++;
			else if (map[v.j][v.c] == 'E')
				v.e_count++;
			v.c++;
		}
		v.j++;
	}
	if (v.p_count != 1 || v.e_count != 1)
		closenkill(lbx, "Error", 1);
}
