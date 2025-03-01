/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:19:06 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/17 17:33:59 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw(t_map *map, int i, int j)
{
	if (map->map[i][j] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->floor, j * 50, i * 50);
	else if (map->map[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall, j * 50, i * 50);
	else if (map->map[i][j] == 'P')
		mlx_put_image_to_window(map->mlx, map->win, map->player, j * 50, i
			* 50);
	else if (map->map[i][j] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->coin[map->coin_frame],
			j * 50, i * 50);
	else if (map->map[i][j] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->exit, j * 50, i * 50);
	else if (map->map[i][j] == 'N')
		mlx_put_image_to_window(map->mlx, map->win, map->enemy, j * 50, i * 50);
}
