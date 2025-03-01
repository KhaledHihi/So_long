/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:10:58 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/23 16:10:01 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	draw_map(t_map *map)
{
	int (i), (j);
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			draw(map, i, j);
			j++;
		}
		i++;
	}
	print_moves_in_window(map);
}

void	move_player(t_map *elm, int move_x, int move_y)
{
	int (new_x), (new_y);
	new_x = elm->player_x + move_x;
	new_y = elm->player_y + move_y;
	if (elm->map[new_y][new_x] == 'N')
		return (ft_printf("You lose!\n"), clean_up(elm), exit(0));
	if (elm->map[new_y][new_x] == '1')
		return ;
	if (elm->map[new_y][new_x] == 'C')
		elm->collectibles--;
	if (elm->map[new_y][new_x] == 'E')
	{
		if (elm->collectibles == 0)
			return (ft_printf("You win!\n"), clean_up(elm), exit(0));
		else
			return ;
	}
	elm->map[elm->player_y][elm->player_x] = '0';
	elm->player_x = new_x;
	elm->player_y = new_y;
	elm->map[new_y][new_x] = 'P';
	draw_map(elm);
	elm->moves++;
}

int	window_close(t_map *elm)
{
	clean_up(elm);
	exit(0);
	return (0);
}

int	animation(t_map *map)
{
	animate_coin(map);
	print_moves_in_window(map);
	return (1);
}

int	run_win(t_map *elm)
{
	elm->mlx = mlx_init();
	if (!elm->mlx)
		return (0);
	elm->win = mlx_new_window(elm->mlx, elm->colums * 50, elm->rows * 50,
			"so_long");
	if (!elm->win)
		return (0);
	if (!file_to_ptr(elm))
		return (clean_up(elm), 0);
	draw_map(elm);
	print_moves_in_window(elm);
	mlx_key_hook(elm->win, &on_keypress, elm);
	mlx_loop_hook(elm->mlx, &animation, elm);
	mlx_hook(elm->win, 17, 0, &window_close, elm);
	mlx_loop(elm->mlx);
	return (1);
}
