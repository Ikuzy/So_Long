/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:26:52 by ozouine           #+#    #+#             */
/*   Updated: 2024/07/04 17:26:24 by ozouine          ###   ########.fr       */
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

char	**main_helper(char **map, int i, char *join)
{
	if (join == NULL)
		closenkill("empty Map File", 1);
	map = ft_split(join, '\n');
	line_len(map, i);
	check_borders(map, i);
	check_comp(map, i);
	count_comp(map, i);
	free(join);
	return (map);
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
		lbx.map = main_helper(lbx.map, v.i, v.join);
		lbx.mlx = mlx_init();
		lbx.mlx_win = mlx_new_window(lbx.mlx, ft_strlen (lbx.map[0]) * 30, v.i * 30, "So_long");
		count_colls(&lbx);
		convert_img(&lbx);
		draw_map(&lbx, 0, 0);
		mlx_key_hook(lbx.mlx_win,move_keys,&lbx);
		mlx_loop(lbx.mlx);
		ft_free(lbx.map, v.i);
	}
}
