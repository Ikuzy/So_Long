/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:26:52 by ozouine           #+#    #+#             */
/*   Updated: 2024/06/28 16:30:12 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	if (ac == 2)
	{
    	char	**map;
		char	*join = NULL;
		size_t		i = 0;
		char	*tmp1;
		char	*tmp;
		char	*tmp2;
		int fd = open(av[1], O_RDONLY);

		tmp1 = get_next_line(fd);
		while (tmp1 != NULL)
		{
			tmp = join;
			tmp2 = tmp1;
			join = ft_strjoin(join, tmp1);
			tmp1 = get_next_line(fd);
			free(tmp2);
			free(tmp);
			i++;
		}
		printf("%s\n", join);
		if (join == NULL)
			closenkill("empty Map File", 1);
		map = malloc (sizeof (char*) * i);
		map = ft_split(join, '\n');
		// while (*map != NULL)
		// {
		// 	printf("%s\n\n", *map);
		// 	map++;
		// }
		
		line_len(map, i);
		check_borders(map, i);
		free (join);
		ft_free(map, i);
	}
}
