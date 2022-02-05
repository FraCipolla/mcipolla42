/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcipolla <mcipolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:45:38 by mcipolla          #+#    #+#             */
/*   Updated: 2022/02/05 18:16:50 by mcipolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_type_val (char c)
{
	if (c == 'd' || c == 'i')
		return (1);
	else if (c == 'u')
		return (1);
	else if (c == 'x')
		return (1);
	else if (c == 'X')
		return (1);
	else if (c == 's')
		return (1);
	else if (c == 'c')
		return (1);
	else if (c == 'p')
		return (1);
	else if (c == '%')
		return (1);
	return (0);
}

int	ft_check_type (char c, t_list *params)
{
		if (ft_type_val(c) == 1)
		{ 
			if (c == 'd' || c == 'i')
				params->di += 1;
			else if (c == 'u')
				params->u += 1;
			else if (c == 'x')
				params->x += 1;
			else if (c == 'X')
				params->X += 1;
			else if (c == 's')
				params->s += 1;
			else if (c == 'c')
				params->c += 1;
			else if (c == 'p')
				params->p += 1;
			else if (c == '%')
			{
				params->percent += 1;
				ft_putchar(c, params);
			}
			return (1);
		}
	
	return (0);
}

void	ft_check_params (char *str, t_list *params)
{
	int		c;
	char	*tab;

	c = -1;
	printf("STR: %s\n", str);
	tab = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[++c])
		{
			if (str[c] == '-')
				params->min += 1;
			if (str[c] == '#')
				params->hash += 1;
			if (str[c] == '.')
				params->dot += 1;
			if (str[c] == ' ')
				params->space += 1;
			if (str[c] == '+')
				params->plus += 1;
			if (str[c] == '0' && (str[c - 1] < '0' || str[c - 1] > '9'))
				params->zero = 1;
			tab[c] = str[c];
		}
	ft_find_width(tab, params);
	if (params->hash == 1)
		params->width -= 2;
	if (params->dot == 1)
		ft_find_precision(tab, params);
}

void	ft_find_width (char *str, t_list *params)
{
	char	*to_atoi;
	int		i;
	int		c;

	i = 0;
	c = 0;
	to_atoi = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (params->zero == 1)
	{
		while (str[i] != '0')
			i++;
		i++;
		while (str[i] < '0' && str[i] > '9')
			i++;
	}
	if (params->zero == 0)
	{
		while ((str[i] < '0' || str[i] > '9') && str[i])
			i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
		to_atoi[c++] = str[i++];
	to_atoi[c] = '\0';
	params->width = ft_atoi(to_atoi);
}

void	ft_find_precision (char *str, t_list *params)
{
	char	*to_atoi;
	int		i;
	int 	c;

	i = 0;
	c = 0;
	while (str[i] != '.')
		i++;
	to_atoi = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		to_atoi[c] = str[i];
		c++;
		i++;
	}
	to_atoi[c] = 0;
	params->precision = ft_atoi(to_atoi);
}

void	ft_utility(t_list *params)
{
	params->min = 0;
	params->zero = 0;
	params->hash = 0;
	params->dot = 0;
	params->space = 0;
	params->plus = 0;
	params->precision = 0;
	params->width = 0;
	params->di = 0;
	params->u = 0;
	params->x = 0;
	params->X = 0;
	params->s = 0;
	params->c = 0;
	params->p = 0;
	params->ret = 0;
	params->percent = 0;
}