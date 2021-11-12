/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:05:55 by rchampli          #+#    #+#             */
/*   Updated: 2021/11/10 16:05:55 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h> 
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
int		ft_putchar(const char s);
int		ft_putstr(const char *s);
char	*ft_strdup(const char *s);
int		ft_treatment_char(char c);
int		ft_treatment_str(char *s);
int		ft_treatment_int(int n);
int		ft_treatment_pointer(unsigned long long ull);
char	*ft_ull_base(unsigned long long ull, int base);

#endif