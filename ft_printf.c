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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(const char s)
{
	write(1, &s, 1);
}

void	ft_putstr(const char *s)
{
	write(1, s, ft_strlen(s));
}

char	*ft_strdup(const char *s)
{
	unsigned int	i;
	unsigned char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(s));
	if (!dest)
		return (0);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_treatment(va_list arg, const char *s)
{
	size_t	i;
	int		done;

	i = 0;
	done = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == 'c')
				done += ft_treatment_char(va_arg(arg, int));
			else if (s[i + 1] == 's')
				done += ft_treatment_str(va_arg(arg, char *));
			else if (s[i + 1] == 'p')
				done += ft_treatment_pointer(va_arg(arg, unsigned long long));
			else if (s[i + 1] == 'd' || s[i + 1] == 'i')
				va_arg(arg, int);
			else if (s[i + 1] == 'u')
				va_arg(arg, unsigned int);
			else if (s[i + 1] == 'x')
			 	va_arg(arg, unsigned int);
			else if (s[i + 1] == '%')
				ft_putchar('%');
			i += 2;
			done += 1;
		}
		else
		{
			ft_putchar(s[i]);
			done++;
		}
		i++;
	}
	return (done);
}

int	ft_printf(const char *s, ...)
{
	va_list arg;
	int		done;
	size_t	i;
	char	*save;

	done = 0;
	save = ft_strdup(s);
	va_start(arg, s);
	done += ft_treatment(arg, save);
	va_end(arg);
	return (done);
}

int	main(void)
{
	char *num = "tg";
	int	n;
	n = ft_printf("Faux: bonjour ça marche %s \n", num);
	printf("%d\n", n);
	n= printf("Vrai: bonjour ça marche %s \n", num);
	printf("%d\n", n);
	return (0);
}
