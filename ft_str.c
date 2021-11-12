/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:29:09 by rchampli          #+#    #+#             */
/*   Updated: 2021/11/12 14:29:09 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(const char s)
{
	int	done;

	done = 1;
	write(1, &s, 1);
	return (done);
}

int	ft_putstr(const char *s)
{
	int	i;

	i = ft_strlen(s);
	write(1, s, i);
	return (i);
}
