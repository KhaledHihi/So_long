/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:14:52 by khhihi            #+#    #+#             */
/*   Updated: 2024/11/12 11:54:46 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_address(void *ptr, int *len)
{
	unsigned long	p;

	p = (unsigned long)ptr;
	ft_putstr("0x", len);
	ft_putnbr_base(p, 'x', len);
}
