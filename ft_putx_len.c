/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 09:10:02 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/25 09:10:03 by mmitrovi         ###   ########.fr       */
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
