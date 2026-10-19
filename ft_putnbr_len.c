/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 09:09:26 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/10/19 11:34:23 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** @brief	why is second time n % 10? if we have number 123
 *			recustion is going to cut number 2 times, 
 *			it cuts and writes 3, and again 2
 *			but then we are back in first recursion with number 123
 *			and then we need to cut number 1 with %
 * @param n 
 * @return length of numbers written on the terminal
 */
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
