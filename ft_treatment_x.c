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

static char	*treat_base(unsigned int nsave, int base,
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

static char	*treat_lower_base(unsigned int nsave, int base,
char *rtn, int count)
{
	while (nsave != 0)
	{
		if ((nsave % base) < 10)
			rtn[count - 1] = (nsave % base) + 48;
		else
			rtn[count - 1] = (nsave % base) + 55;
		nsave /= base;
		count--;
	}
	return (rtn);
}

char	*ft_n_base(unsigned long long ull, int base, int b)
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
	if (b == 0)
		dest = treat_lower_base(ullsave, base, dest, i);
	else
		dest = treat_base(ullsave, base, dest, i);
	return (dest);
}

int	ft_treatment_x(unsigned int n, int b)
{
	char	*pointer;
	int		done;

	done = 0;
	n = (unsigned int)(4294967295 + 1 + n);
	if (b == 1)
		pointer = ft_n_base(n, 16, b);
	else
		pointer = ft_n_base(n, 16, b);
	done += ft_strlen(pointer);
	ft_putstr(pointer);
	free(pointer);
	return (done);
}
