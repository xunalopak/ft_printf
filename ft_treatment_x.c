/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:54:39 by rchampli          #+#    #+#             */
/*   Updated: 2021/11/15 10:54:39 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*treat_base(int nsave, int base,
char *rtn, int count)
{
	while (nsave != 0)
	{
		if ((nsave % base) < 10)
			rtn[count - 1] = (nsave % base) + 48;
		else
			rtn[count - 1] = (nsave % base) + 55 + 32;
		nsave /= base;
		count--;
	}
	return (rtn);
}

static char	*ft_n_base(int n, int base)
{
	char	*dest;
	int		nsave;
	size_t	i;

	i = 0;
	nsave = n;
	if (!nsave)
		return (ft_strdup("0"));
	while (nsave)
	{
		nsave /= base;
		i++;
	}
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	dest[i] = '\0';
	dest = treat_base(nsave, base, dest, i);
	return (dest);
}

int	ft_treatment_x(int n)
{
	char	*pointer;
	int		done;

	done = 0;
	pointer = ft_ull_base(n, 16);
	done += ft_strlen(pointer);
	ft_putstr(pointer);
	free(pointer);
	return (done);
}
