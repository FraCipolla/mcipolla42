/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcipolla <mcipolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:35:38 by mcipolla          #+#    #+#             */
/*   Updated: 2022/01/29 17:23:05 by mcipolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

int	ft_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && ft_sep(s[i], c) == 0)
		i++;
	return (i);
}

int	ft_find_size(const char *s, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (*s)
	{
		if (ft_sep (*s, c) == 1)
			s++;
		i = ft_len(s, c);
		s += i;
		if (i)
			x++;
	}
	return (x);
}

char	*ft_malloc_strcpy(const char *s, int n)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc((n + 1) * sizeof(char));
	if (!dst)
		return (0);
	while (i < n && s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		x;
	char	**dst;
	int		size;

	i = 0;
	x = 0;
	size = ft_find_size(s, c);
	dst = malloc((size + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	while (x < size)
	{
		while (ft_sep(*s, c))
			s++;
		i = ft_len(s, c);
		dst[x] = ft_malloc_strcpy(s, i);
		s += i;
		x++;
	}
	dst[size] = 0;
	return (dst);
}
