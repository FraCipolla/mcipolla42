/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcipolla <mcipolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:45:31 by mcipolla          #+#    #+#             */
/*   Updated: 2022/02/04 14:25:03 by mcipolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_print_direv_dot (long int args, int len, t_list *params)
{
	if (params->plus == 1 && args >= '0')
	{
		ft_putchar ('+', params);
		params->space = 0;
		params->width -= 1;
	}
	if (args < '0')
	{
		ft_putchar ('-', params);
		args *= -1;
		params->space = 0;
		params->width -= 1;
	}
	while (params->precision > len++)
		ft_putchar ('0', params);
	ft_putstr(ft_itoa(args), params);
	while (params->width > len++)
		ft_putchar (' ', params);
}

void	ft_print_direv (long int args, int len, t_list *params)
{
	if (params->dot == 0)
	{
		if (params->plus == 1 && args >= 0)
		{
			ft_putchar ('+', params);
			params->width -= 1;
			params->space = 0;
		}
		if (args < '0')
		{
			ft_putchar ('-', params);
			args *= -1;
			params->width -= 1;
			params->space = 0;
		}
		ft_putstr(ft_itoa(args), params);
		while (params->width > len++)
			ft_putchar (' ', params);
	}
	else
		ft_print_direv_dot (args, len, params);
}

void	ft_print_prec(long int args, int len, t_list *params)
{
	if (params->min == 1)
		ft_print_direv_dot(args, len, params);
	else
	{
		if (params->width > params->precision)
			while (params->width-- > params->precision)
				ft_putchar (' ', params);
		if (params->plus == 1 && args >= 0)
		{
			ft_putchar('+', params);
			params->space = 0;
			params->width -= 1;
		}
		if (args < 0)
		{
			ft_putchar('-', params);
			args *= -1;
			params->space = 0;
			params->width -= 1;
		}
		while (params->precision-- > len)
			ft_putchar('0', params);
		ft_putstr(ft_itoa(args), params);
	}
}

void	ft_print_zero(long int args, int len, t_list *params)
{
	if (params->plus == 1 && args >= 0)
	{
		ft_putchar ('+', params);
		params->space = 0;
		params->width -= 1;
	}
	if (args < '0')
	{
		ft_putchar ('-', params);
		args *= -1;
		params->space = 0;
		params->width -= 1;
	}
	while (params->width > len++)
		ft_putchar ('0', params);
	ft_putstr(ft_itoa(args), params);
}

void	ft_print_di(long int args, t_list *params)
{
	int	len;
	int size;

	len = 0;
	size = args;
	while (size != 0)
	{
		size /= 10;
		len++;
	}
	if (params->dot == 1)
	{
		ft_print_prec(args, len, params);
		return ;
	}
	if (params->min == 1)
	{
		ft_print_direv (args, len, params);
		return ;
	}
	if (params->zero == 1)
		ft_print_zero(args, len, params);
	if (params->plus == 1 && args >= 0)
	{
		ft_putchar ('+', params);
		params->space = 0;
		params->width -= 1;
	}
	if (args < 0)
	{
		ft_putchar ('-', params);
		args *= -1;
		params->space = 0;
		params->width -= 1;
	}
	//printf("\nPRINT_DI: %d\n", args);
	ft_putstr(ft_itoa(args), params);
	while (params->width > len++)
			ft_putchar ('0', params);
}