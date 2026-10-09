/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 09:09:35 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/25 09:09:38 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

/*
NULL is an adress pointing nowhere has value of 0
null is just a text which printf prints,
if I send NULL pointer with %s (specificator) 
nil is just a text which printf prints,
if I send NULL pointer with %p (specificator) 
nil is short of latin nihil = nothing
*/