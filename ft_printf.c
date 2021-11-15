/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:00:48 by rchampli          #+#    #+#             */
/*   Updated: 2021/11/10 16:00:48 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat(char s, va_list arg)
{
	int	done;

	done = 0;
	if (s == 'c')
		done += ft_treatment_char(va_arg(arg, int));
	else if (s == 's')
		done += ft_treatment_str(va_arg(arg, char *));
	else if (s == 'p')
		done += ft_treatment_pointer(va_arg(arg, unsigned long long));
	else if (s == 'd' || s == 'i')
		done += ft_treatment_int(va_arg(arg, int));
	else if (s == 'u')
		done += ft_treatment_uint(va_arg(arg, unsigned int));
	else if (s == 'x')
		done += ft_treatment_x(va_arg(arg, unsigned int), 1);
	else if (s == 'X')
		done += ft_treatment_x(va_arg(arg, unsigned int), 0);
	else if (s == '%')
		done += ft_putchar('%');
	return (done);
}

int	ft_treatment(va_list arg, const char *s)
{
	size_t	i;
	int		done;

	i = -1;
	done = 0;
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			done += ft_treat(s[i + 1], arg);
			i += 1;
		}
		else
			done += ft_putchar(s[i]);
	}
	return (done);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		done;
	size_t	i;
	char	*save;

	done = 0;
	save = ft_strdup(s);
	va_start(arg, s);
	done += ft_treatment(arg, save);
	va_end(arg);
	free(save);
	return (done);
}
