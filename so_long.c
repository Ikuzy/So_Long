/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:26:52 by ozouine           #+#    #+#             */
/*   Updated: 2024/07/04 20:34:30 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	main_helper(t_mlx *lbx, int i, char *join)
{
	if (join == NULL)
		closenkill(lbx, "empty Map File", 1);
	lbx->map = ft_split(join, '\n');
	lbx->map_dup = ft_split(join, '\n');
	line_len(lbx, lbx->map, i);
	check_borders(lbx, lbx->map, i);
	check_comp(lbx, lbx->map, i);
	count_comp(lbx, lbx->map, i);
	free(join);
}
void	innit(t_mlx *lbx, t_var *v, char *str)
{
	v->i = 0;
	v->join = NULL;
	v->fd = open(str, O_RDONLY);
	v->get_line = get_next_line(v->fd);
	lbx->count_mv = 0;
	lbx->map = NULL;
	while (v->get_line != NULL)
	{
		v->free_j = v->join;
		v->free_l = v->get_line;
		v->join = ft_strjoin(v->join, v->get_line);
		v->get_line = get_next_line(v->fd);
		free(v->free_l);
		free(v->free_j);
		v->i++;
	}
}

int	main(int ac, char **av)
{
	t_mlx	lbx;
	t_var	v;

	if (ac == 2)
	{
		innit(&lbx, &v, av[1]); 
		main_helper(&lbx, v.i, v.join);
		count_colls(&lbx);
		ft_validate_path(&lbx, v.i);
		lbx.mlx = mlx_init();
		if (lbx.mlx == NULL)
			return (1);
		lbx.mlx_win = mlx_new_window(lbx.mlx, ft_strlen (lbx.map[0]) * 30, v.i * 30, "So_long");
		convert_img(&lbx);
		draw_map(&lbx, 0, 0);
		mlx_key_hook(lbx.mlx_win,move_keys,&lbx);
		mlx_loop(lbx.mlx);
		ft_free(lbx.map);
		mlx_destroy_window(lbx.mlx, lbx.mlx_win);
	}
}
