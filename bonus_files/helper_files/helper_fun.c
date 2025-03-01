/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:17:15 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/26 15:33:15 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*ft_strdup(const char *s)
{
	int		len;
	char	*d;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen((char *)s);
	d = ft_malloc(sizeof(char) * (len + 1), 1);
	if (!d)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*d;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	d = ft_malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (!d)
		return (free(s1), NULL);
	if (s1)
		while (s1[i])
			d[j++] = s1[i++];
	j = 0;
	while (s2[j])
	{
		d[i + j] = s2[j];
		j++;
	}
	d[i + j] = '\0';
	return (d);
}

int	check_size(t_map *elm)
{
	int		i;
	size_t	resolution;

	i = 1;
	resolution = ft_strlen(elm->map[0]);
	elm->colums = resolution - 1;
	while (elm->map[i])
	{
		if (resolution != ft_strlen(elm->map[i]))
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
