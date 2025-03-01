/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:22:11 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/19 19:26:09 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	check_valid_char(t_map *elm)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (elm->map[i])
	{
		j = 0;
		while (elm->map[i][j])
		{
			if (elm->map[i][j] != 'P' && elm->map[i][j] != 'C'
				&& elm->map[i][j] != 'E' && elm->map[i][j] != '1'
				&& elm->map[i][j] != '0' && elm->map[i][j] != '\n'
				&& elm->map[i][j] != 'N')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	increm(t_map *elm, int i, char *line, int *E)
{
	if (line[i] == 'E')
		(*E)++;
	if (line[i] == 'C')
		elm->coins++;
	if (line[i] == 'N')
		elm->count_enemy++;
}

int	check_valid_charcter(int fd, t_map *elm)
{
	char	*line;

	int (i), (P), (E);
	P = 0;
	E = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = -1;
		while (line[++i])
		{
			if (line[i] == 'P')
				P++;
			increm(elm, i, line, &E);
		}
		elm->rows++;
		free(line);
		line = get_next_line(fd);
	}
	get_next_line(-2);
	if (P == 1 && elm->coins != 0 && E == 1 && elm->count_enemy > 0)
		return (close(fd), 1);
	return (0);
}

char	**read_map(int fd, t_map *data, char *file_name)
{
	int		i;
	char	**map;

	i = 0;
	fd = open(file_name, O_RDONLY);
	map = malloc(sizeof(char *) * (data->rows + 1));
	if (!map)
		return (NULL);
	while (data->rows > i)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	get_next_line(-2);
	map[i] = NULL;
	return (map);
}

int	check_map(char *file_name, t_map *elm)
{
	int	fd;

	*elm = (t_map){0};
	fd = open(file_name, O_RDONLY);
	if (!check_valid_charcter(fd, elm))
		return (0);
	elm->map = read_map(fd, elm, file_name);
	if (!check_size(elm))
		return (free_arr(elm->map, elm->rows), 0);
	if ((check_valid_char(elm)) == 0)
		return (free_arr(elm->map, elm->rows), 0);
	if (check_walls(elm) == 0)
		return (free_arr(elm->map, elm->rows), 0);
	if (flood_fill(elm) == 0)
		return (free_arr(elm->map, elm->rows), 0);
	if (elm->colums > 77 || elm->rows > 42)
		return (free_arr(elm->map, elm->rows), 0);
	return (1);
}
