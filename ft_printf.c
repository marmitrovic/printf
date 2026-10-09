/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:21:12 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 19:45:37 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		letter_counter;
	va_list	args;

	i = 0;
	letter_counter = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			letter_counter += ft_putchar_len(str[i]);
		}
		else if (str[i] == '%' && str[i + 1] == 'c')
		{
			letter_counter += ft_putchar_len(va_arg(args, int));
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			letter_counter += ft_putchar_len('%');
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 's')
		{
			letter_counter += ft_putstr_len(va_arg(args, char *));
			i++;
		}
		else if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
		{
			letter_counter += ft_putnbr_len(va_arg(args, int));
			i++;
		}
		else if (str[i] == '%' && (str[i + 1] == 'u'))
		{
			letter_counter += ft_putuint_len(va_arg(args, unsigned int));
			i++;
		}
		else if (str[i] == '%' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		{
			letter_counter += ft_putx_len(va_arg(args, unsigned int), str[i + 1]);
			i++;
		}
		else if (str[i] == '%' && (str[i + 1] == 'p'))
		{
			letter_counter += ft_putp_len(va_arg(args, unsigned long));
			i++;
		}
		i++;
	}
	va_end(args);
	return (letter_counter);
}

	/*
	standard printf returns -1 if forwarded invalid pointer
	because ft_putchar_len.c returns 1, 
	I can concatenate with counters(letter_counter) 
	designers define it like this: va_arg(list_name, tip_podatka)
	i zato ih pisemo tako sta ide prvo a sta ide drugo. 
	NULL is in a library, so !src is always more secure way
			to check is it NULL then asking NULL
	*/