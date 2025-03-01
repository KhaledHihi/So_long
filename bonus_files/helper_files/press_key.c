/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:43:20 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/17 17:43:34 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
