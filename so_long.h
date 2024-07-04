/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:27:02 by ozouine           #+#    #+#             */
/*   Updated: 2024/07/04 20:41:58 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "GNL/get_next_line.h"
# include "MLX/mlx.h"

typedef struct s_var
{
	char	*join;
	int		i;
	char	*get_line;
	char	*free_j;
	char	*free_l;
	int		fd;
	int		j;
	int		c;
	int		len;
	int		p_count;
	int		e_count;
	int		c_count;
}	t_var;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	**map_dup;
	void	*player;
	void	*ground;
	void	*wall;
	void	*exit;
	void	*coll;
	int		count_mv;
	int		count_coll;
	
}	t_mlx;

char	**ft_free(char **s);
char	**ft_split(char const *s, char c);
void	closenkill(t_mlx *lbx, char *str, int i);
void	line_len(t_mlx *lbx, char **map, int i);
void	check_borders(t_mlx *lbx, char **map, int i);
void	check_comp(t_mlx *lbx, char **map, int i);
void	count_comp(t_mlx *lbx, char **map, int i);
void	main_helper(t_mlx *lbx, int i, char *join);
int		ft_strlen(char *str);
void	convert_img(t_mlx *lbx);
void	draw_map(t_mlx *lbx, int i, int j);
void	player_position(t_mlx *lbx, int *i, int *j);
int		move_player(t_mlx *lbx, int yp, int xp);
int		move_keys(int keycode, t_mlx *lbx);
void	count_colls(t_mlx *lbx);
void	innit(t_mlx *lbx, t_var *v, char *str);
void	ft_floodfill(char **tab, int x, int y, int i, int j);
void	ft_check_floodfill(t_mlx *lbx, char **map);
void	ft_validate_path(t_mlx *app, int len);


#endif