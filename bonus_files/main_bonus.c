/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:21:16 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/20 16:39:03 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_map	elm;

	if (ac != 2 || !check_file_name(av[1]))
		return (ft_printf("Error\nNo such file or directory !\n"), 1);
	if (check_map(av[1], &elm) == 0)
		return (ft_printf("Error\nInvalid map !\n"), 1);
	if (!run_win(&elm))
		return (ft_printf("Error\nWindow is not running !\n"), 1);
}
