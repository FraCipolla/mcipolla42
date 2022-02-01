/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcipolla <mcipolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:53:34 by mcipolla          #+#    #+#             */
/*   Updated: 2022/02/01 11:03:26 by mcipolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_c(va_list args, t_list *params)
{
	if (params->min == 1 && params->width > 1)
	{
		ft_putchar(args);
		while (params->witdh -= -1 > 1)
			ft_putchar(' ');
	}
	else
	{
		while (params->witdh -= -1 > 1)
			ft_putchar(' ');
		ft_putchar(args);
	}
}