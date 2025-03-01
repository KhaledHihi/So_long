/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:43:20 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/14 18:33:46 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clean_up(t_map *elm)
{
	if (elm->floor)
		mlx_destroy_image(elm->mlx, elm->floor);
	if (elm->wall)
		mlx_destroy_image(elm->mlx, elm->wall);
	if (elm->player)
		mlx_destroy_image(elm->mlx, elm->player);
	if (elm->coin)
		mlx_destroy_image(elm->mlx, elm->coin);
	if (elm->exit)
		mlx_destroy_image(elm->mlx, elm->exit);
	if (elm->win)
		mlx_destroy_window(elm->mlx, elm->win);
	if (elm->mlx)
	{
		mlx_destroy_display(elm->mlx);
		free(elm->mlx);
	}
	free_arr(elm->map, elm->rows);
}

void	free_arr(char **p, int rows)
{
	while (rows > 0)
	{
		rows--;
		free(p[rows]);
	}
	free(p);
}
