/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 09:09:26 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/25 09:09:28 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_len(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		len += ft_putchar_len('-');
		n = -n;
	}
	if (n > 9)
	{
		len += ft_putnbr_len(n / 10);
		len += ft_putnbr_len(n % 10);
	}
	else
		len += ft_putchar_len(n + '0');
	return (len);
}
