/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:22:51 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 18:22:52 by marko            ###   ########.fr       */
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