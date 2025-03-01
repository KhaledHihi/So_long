/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:10:58 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/23 15:59:46 by khhihi           ###   ########.fr       */
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
}

void	move_player(t_map *elm, int move_x, int move_y)
{
	int (new_x), (new_y);
	new_x = elm->player_x + move_x;
	new_y = elm->player_y + move_y;
	if (elm->map[new_y][new_x] == '1')
		return ;
	if (elm->map[new_y][new_x] == 'C')
	{
		elm->collectibles--;
		elm->map[new_y][new_x] = '0';
	}
	if (elm->map[new_y][new_x] == 'E')
	{
		if (elm->collectibles == 0)
			return (ft_printf("moves: %d\n", ++(elm->moves)),
				ft_printf("You win!\n"), clean_up(elm), exit(0));
		else
			return ;
	}
	elm->map[elm->player_y][elm->player_x] = '0';
	elm->player_x = new_x;
	elm->player_y = new_y;
	elm->map[new_y][new_x] = 'P';
	draw_map(elm);
	ft_printf("moves: %d\n", ++(elm->moves));
}

int	on_keypress(int key_code, t_map *elm)
{
	if (key_code == XK_Escape)
	{
		clean_up(elm);
		exit(0);
	}
	else if (key_code == XK_w || key_code == XK_Up)
		move_player(elm, 0, -1);
	else if (key_code == XK_s || key_code == XK_Down)
		move_player(elm, 0, 1);
	else if (key_code == XK_a || key_code == XK_Left)
		move_player(elm, -1, 0);
	else if (key_code == XK_d || key_code == XK_Right)
		move_player(elm, 1, 0);
	return (1);
}

int	window_close(t_map *elm)
{
	clean_up(elm);
	exit(0);
	return (0);
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
	mlx_key_hook(elm->win, &on_keypress, elm);
	mlx_hook(elm->win, 17, 0, &window_close, elm);
	mlx_loop(elm->mlx);
	return (1);
}
