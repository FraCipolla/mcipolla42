/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printxX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcipolla <mcipolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:56:55 by mcipolla          #+#    #+#             */
/*   Updated: 2022/02/01 11:11:42 by mcipolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_hexdev (char *str, int len, t_list *params)
{
	while (params->width > len++)
		ft_putchar ('0');
	ft_putstr(str);
	params -> zero = 0;
}

void	ft_print_precision (va_list args, t_list *params)
{
	params->precision -= params->width;

	while (params->precision > 0)
	{
		ft_putchar('0');
		params->precision -= 1;
	}
}

void	ft_print_hex(va_list args, t_list *params)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa_hex(args);
	while (str[len++])
	if (params->min == 1 && params->dot == 0)
	{
		ft_print_direv (str, len);
		return ;
	}
	while (params->width - 1 > len++ && params->zero == 0)
		ft_putchar (' ');
	
	while (params->width > len++)
			ft_putchar ('0');
	}
	ft_putstr(ft_itoa(args));
}