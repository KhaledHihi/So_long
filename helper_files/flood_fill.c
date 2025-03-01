/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:31:22 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/13 12:49:07 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_if_the_player(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	to_fill(t_map *map, char **the_map, int y, int x)
{
	if (y >= map->rows || x >= map->colums || y < 0 || x < 0)
		return ;
	if (the_map[y][x] != 'C' && the_map[y][x] != 'P' && the_map[y][x] != '0'
		&& the_map[y][x] != 'E')
		return ;
	if (the_map[y][x] == 'C')
		map->collectibles++;
	if ((map->map[y][x] == 'E') && (map->collectibles != map->coins))
	{
		the_map[y][x] = 'V';
		return ;
	}
	the_map[y][x] = 'V';
	to_fill(map, the_map, y + 1, x);
	to_fill(map, the_map, y - 1, x);
	to_fill(map, the_map, y, x + 1);
	to_fill(map, the_map, y, x - 1);
}

int	flood_fill(t_map *map)
{
	char	**the_map;

	int (i), (j);
	i = -1;
	the_map = malloc(sizeof(char *) * (map->rows + 1));
	while (++i < map->rows)
	{
		j = -1;
		the_map[i] = malloc(sizeof(char) * (map->colums + 1));
		while (++j < map->colums)
		{
			the_map[i][j] = map->map[i][j];
			if (the_map[i][j] == 'P')
			{
				map->player_y = i;
				map->player_x = j;
			}
		}
		the_map[i][j] = '\0';
	}
	the_map[i] = NULL;
	to_fill(map, the_map, map->player_y, map->player_x);
	if (check_if_the_player(the_map) == 0)
		return (free_arr(the_map, map->rows), 0);
	return (free_arr(the_map, map->rows), 1);
}
