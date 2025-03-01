/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:51:29 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/23 16:01:04 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	animate_coin(t_map *map)
{
	static int	frame_counter;
	const int	delay = 50;

	frame_counter++;
	if (frame_counter >= delay)
	{
		frame_counter = 0;
		map->coin_frame = (map->coin_frame + 1) % 10;
	}
	draw_map(map);
}
