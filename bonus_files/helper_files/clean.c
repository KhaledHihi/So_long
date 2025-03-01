/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:43:20 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/27 19:47:48 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clean_coins(t_map *elm)
{
	int	i;

	i = 9;
	while (i >= 0)
	{
		if (elm->coin[i])
			mlx_destroy_image(elm->mlx, elm->coin[i]);
		i--;
	}
}

void	clean_up(t_map *elm)
{
	if (elm->floor)
		mlx_destroy_image(elm->mlx, elm->floor);
	if (elm->wall)
		mlx_destroy_image(elm->mlx, elm->wall);
	if (elm->player)
		mlx_destroy_image(elm->mlx, elm->player);
	if (elm->exit)
		mlx_destroy_image(elm->mlx, elm->exit);
	if (elm->enemy)
		mlx_destroy_image(elm->mlx, elm->enemy);
	if (elm->win)
		mlx_destroy_window(elm->mlx, elm->win);
	clean_coins(elm);
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
