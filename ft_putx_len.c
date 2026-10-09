/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:23:00 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 18:23:01 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putx_len(unsigned int n, char format)
{
	int	len;

	len = 0;
	if (n > 15)
	{
		len += ft_putx_len(n / 16, format);
		len += ft_putx_len(n % 16, format);
	}
	else if (n <= 9)
	{
		len += ft_putchar_len(n + '0');
	}
	else
	{
		if (format == 'x')
			len += ft_putchar_len(n - 10 + 'a');
		else if (format == 'X')
			len += ft_putchar_len(n - 10 + 'A');
	}
	return (len);
}
