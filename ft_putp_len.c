/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 09:09:35 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/10/19 12:03:48 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** @brief		like putnbr cuts all numbers but last recursion needs
 * 				first number that is why I have % for first number
 * 				numbers up to 9 just write them
 * 				num 10 ~ 16 Subtract 10 + a, because they are letters a - f
 * @param ptr	memory address (pointer) occupy 8 bytes and
 * 				cant fit in one int (4bytes)
 * @return length
*/
static	int	ft_putptr_hex(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr > 15)
	{
		len += ft_putptr_hex(ptr / 16);
		len += ft_putptr_hex(ptr % 16);
	}
	else if (ptr <= 9)
	{
		len += ft_putchar_len(ptr + '0');
	}
	else
		len += ft_putchar_len(ptr - 10 + 'a');
	return (len);
}

/** @brief		NULL is an adress pointing nowhere has value of 0
 * 				null is just a text which printf prints
 * 				nil is short of latin nihil = nothing
 * @param ptr 
 * @return 
*/
int	ft_putp_len(unsigned long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = ft_putstr_len("0x");
	len += ft_putptr_hex(ptr);
	return (len);
}
