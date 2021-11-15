/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:05:04 by rchampli          #+#    #+#             */
/*   Updated: 2021/11/12 12:05:04 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treatment_str(char *s)
{
	int	done;

	done = 0;
	if (!s)
		done += ft_putstr("(null)");
	else
		done += ft_putstr(s);
	return (done);
}
