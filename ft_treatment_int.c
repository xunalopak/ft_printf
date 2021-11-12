/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:49:14 by rchampli          #+#    #+#             */
/*   Updated: 2021/11/12 14:49:14 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nb_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nb;

	len = ft_nb_len(n);
	nb = n;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nb)
	{
		str[len] = nb % 10 + '0';
		len--;
		nb = nb / 10;
	}
	return (str);
}

int	ft_treatment_int(int n)
{
	int	done;

	done = 0;
	done = ft_nb_len(n);
	ft_putstr(ft_itoa(n));
	return (done);
}
