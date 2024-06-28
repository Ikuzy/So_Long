/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:26:52 by ozouine           #+#    #+#             */
/*   Updated: 2024/06/28 18:57:41 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void main_helper(char **map, size_t i, char *join)
{
	if (join == NULL)
		closenkill("empty Map File", 1);
	map = malloc (sizeof (char*) * i);
	map = ft_split(join, '\n');
	line_len(map, i);
	check_borders(map, i);
	check_comp(map, i);
	count_comp(map, i);
	printf ("%s\n", join);
	free(join);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		void	*mlx;
		void	*mlx_win;
    	char	**map;
		char	*join;
		size_t	i;
		char	*get_line;
		char	*free_join;
		char	*free_line;
		int		fd;

		i = 0;
		map = NULL;
		join = NULL;
		fd = open(av[1], O_RDONLY);
		get_line = get_next_line(fd);
		while (get_line != NULL)
		{
			free_join = join;
			free_line = get_line;
			join = ft_strjoin(join, get_line);
			get_line = get_next_line(fd);
			free(free_line);
			free(free_join);
			i++;
		}
		main_helper(map, i, join);
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 500, 250, "Hello world!");
		mlx_loop(mlx);
		ft_free(map, i);
	}
}
