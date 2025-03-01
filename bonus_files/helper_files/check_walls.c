/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:08:19 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/17 17:35:57 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_walls(t_map *elm)
{
	char	**the_map;

	int (i), (j), (row), (col);
	i = 0;
	the_map = elm->map;
	row = elm->rows;
	col = elm->colums;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (i == 0 && the_map[i][j] != '1')
				return (0);
			if (i == row - 1 && the_map[i][j] != '1')
				return (0);
			if (j == 0 && the_map[i][j] != '1')
				return (0);
			if (j == col - 1 && the_map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
