/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:37:44 by khhihi            #+#    #+#             */
/*   Updated: 2024/11/15 17:41:58 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check(char c, va_list args, int *i)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), i);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), i);
	else if (c == 'p')
		ft_printf_address(va_arg(args, void *), i);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), i);
	else if (c == 'u')
		ft_putunbr(va_arg(args, unsigned int), i);
	else if (c == 'x' || c == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), c, i);
	else if (c != '\0')
		ft_putchar(c, i);
}

int	ft_printf(const char *f, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, f);
	if (write(1, 0, 0))
		return (-1);
	i = 0;
	count = 0;
	while (f[i])
	{
		if (f[i] == '%')
		{
			i++;
			ft_check(f[i], args, &count);
		}
		else
			ft_putchar(f[i], &count);
		if (count == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return (count);
}
