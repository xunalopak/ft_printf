/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:17:31 by rchampli          #+#    #+#             */
/*   Updated: 2021/11/12 12:17:31 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*treat_base(unsigned long long ull_save, int base,
char *rtn, int count)
{
	while (ull_save != 0)
	{
		if ((ull_save % base) < 10)
			rtn[count - 1] = (ull_save % base) + 48;
		else
			rtn[count - 1] = (ull_save % base) + 55 + 32;
		ull_save /= base;
		count--;
	}
	return (rtn);
}

char	*ft_ull_base(unsigned long long ull, int base)
{
	char				*dest;
	unsigned long long	ullsave;
	size_t				i;

	i = 0;
	ullsave = ull;
	if (!ull)
		return (ft_strdup("0"));
	while (ull)
	{
		ull /= base;
		i++;
	}
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	dest[i] = '\0';
	dest = treat_base(ullsave, base, dest, i);
	return (dest);
}

int	ft_treatment_pointer(unsigned long long ull)
{
	char	*pointer;
	int		done;

	done = 0;
	ft_putstr("0x");
	pointer = ft_ull_base(ull, 16);
	done += ft_strlen(pointer);
	ft_putstr(pointer);
	free(pointer);
	return (done += 2);
}
