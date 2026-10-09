/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:23:07 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 18:23:08 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
	{
		len += ft_putuint_len(n / 10);
		len += ft_putuint_len(n % 10);
	}
	else
		len += ft_putchar_len(n + '0');
	return (len);
}

/*
uint - unsigned int -
 just positive numbers (0 included) 0 up to 4,294,967,295

 because of that I dont need to check INT_MIN
 and also no need to check negatives (unsigned int)

 int len ( becuase this function returns int, no need for 
 unsigned int len, becuase I cant return it)


*/