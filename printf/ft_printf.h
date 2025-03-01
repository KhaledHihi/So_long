/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:40:58 by khhihi            #+#    #+#             */
/*   Updated: 2024/11/15 17:39:24 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *i);
void	ft_putnbr(long n, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putnbr_base(unsigned long nb, char c, int *len);
void	ft_printf_address(void *ptr, int *len);
void	ft_putunbr(unsigned long n, int *len);

#endif
