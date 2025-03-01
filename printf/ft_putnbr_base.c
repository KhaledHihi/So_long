/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:08:53 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/17 16:18:16 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long nb, char c, int *len)
{
	char	*l;
	char	*u;

	l = "0123456789abcdef";
	u = "0123456789ABCDEF";
	if (nb < 16)
	{
		if (c == 'x')
			ft_putchar(l[nb], len);
		else if (c == 'X')
			ft_putchar(u[nb], len);
	}
	else if (nb >= 16)
	{
		ft_putnbr_base(nb / 16, c, len);
		ft_putnbr_base(nb % 16, c, len);
	}
}
