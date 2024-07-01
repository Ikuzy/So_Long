/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:07:06 by ozouine           #+#    #+#             */
/*   Updated: 2024/07/01 22:56:21 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_moves(t_mlx *lbx)
{
	lbx->count_mv++;
}

void	player_position(t_mlx *lbx)
{
	int	s;
	int	x;

	s = 0;
	while (lbx->map[s])
	{
		x = 0;
		while (lbx->map[s][x])
		{
			if (lbx->map[s][x] == 'P')
			{
				lbx->ip = s;
				lbx->jp = x;
			}
			else if (lbx->map[s][x] == 'C')
				lbx->count_coll++;
			x++;
		}
		s++;
	}
	
}

int	move_player(t_mlx *lbx)
{
	player_position(lbx);
	if (lbx->map[lbx->ip + lbx->yp][lbx->jp + lbx->xp] == '1')
		return (0);
	else if (lbx->map[lbx->ip + lbx->yp][lbx->jp + lbx->xp] == 'C')
		count_moves(lbx);
	else if (lbx->map[lbx->ip + lbx->yp][lbx->jp + lbx->xp] == 'E' && lbx->count_coll != 0)
		return (0);
	else if (lbx->map[lbx->ip + lbx->yp][lbx->jp + lbx->xp] == 'E'  && lbx->count_coll != 0)
	{
		count_moves(lbx);
		printf("congrats you won\n");
	}
	lbx->map[lbx->ip][lbx->jp] = '0';
	lbx->map[lbx->ip + lbx->yp][lbx->jp + lbx->xp] = 'P';
	mlx_clear_window(lbx->mlx, lbx->mlx_win);
	if (lbx->yp != 0 || lbx->xp != 0)
		count_moves(lbx);
	
}

int	move_keys(int keycode, t_mlx *lbx)
{
    lbx->yp = 0;
    lbx->xp = 0;
    if (keycode == 65362 || keycode == 119)
        lbx->yp = -1;
    else if (keycode == 65364 || keycode == 115)
        lbx->yp = 1;
    else if (keycode == 65363 || keycode == 100)
        lbx->xp = 1;
    else if (keycode == 65361 || keycode == 97)
        lbx->xp = -1;
	
    
}