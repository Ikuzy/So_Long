/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:27:02 by ozouine           #+#    #+#             */
/*   Updated: 2024/06/29 21:55:32 by ozouine          ###   ########.fr       */
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
	void	*player;
	void	*ground;
	void	*wall;
	void	*exit;
	void	*coll;
}	t_mlx;

char	**ft_free(char **s, int j);
char	**ft_split(char const *s, char c);
void	closenkill(char *str, int i);
void	line_len(char **map, int i);
void	check_borders(char **map, int i);
void	check_comp(char **map, int i);
void	count_comp(char **map, int i);
char	**main_helper(char **map, int i, char *join);
int		ft_strlen(char *str);
void	convert_img(t_mlx *lbx);
void	draw_map(t_mlx *lbx, int i, int j);

#endif