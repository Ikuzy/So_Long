/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:21:41 by ozouine           #+#    #+#             */
/*   Updated: 2024/07/04 20:24:44 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_floodfill(char **tab, int x, int y, int i, int j)
{
	if (x < 0 || y < 0 || x >= i || y >= j) 
        return;
	if (tab[x][y] == '1' || tab[x][y] == 'O' )
		return;
	if(tab[x][y] == 'E' )
	{
		tab[x][y] = 'O';
		return ;
	}
		
	
	tab[x][y] = 'O';
	ft_floodfill(tab, (x + 1), y, i, j);
	ft_floodfill(tab, (x - 1), y, i, j);
	ft_floodfill(tab, x, (y + 1), i, j);
	ft_floodfill(tab, x, (y - 1), i, j);
}

void ft_check_floodfill(t_mlx *lbx, char **map)
{
	int i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'E')
				closenkill(lbx, "Player can't reach the Exit", 1);
			else if(map[i][j] == 'C')
				closenkill(lbx, "Player can't reach all Collectibles", 1);
			j++;
		}
		i++;
	}
}

void	ft_validate_path(t_mlx *lbx, int len)
{
	int	x;
	int	y;
	int	k;
    
	k = ft_strlen(lbx->map_dup[0]);
	player_position(lbx , &x, &y);
	ft_floodfill(lbx->map_dup, 1, 2, len, k);
	ft_check_floodfill(lbx, lbx->map_dup);
}
