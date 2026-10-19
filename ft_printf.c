/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 09:08:57 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/10/19 12:18:08 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** @brief			a static function that takes args 
*					and based on specifier calls appropriate functions
* @param args		designers define it like this: va_arg(list_name, data_type)
*					i zato ih pisemo tako sta ide prvo a sta ide drugo.
					now I am taking args manually from the bucket
					but need to spec which type is that arg.
* @param specifier	is just a char that I decided what is going to represent
* @return 			just returns length of characters in total
*/
static int	ft_format(va_list args, char specifier)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len += ft_putchar_len(va_arg(args, int));
	else if (specifier == 's')
		len += ft_putstr_len(va_arg(args, char *));
	else if (specifier == 'p')
		len += ft_putp_len(va_arg(args, unsigned long));
	else if (specifier == 'd' || specifier == 'i')
		len += ft_putnbr_len(va_arg(args, int));
	else if (specifier == 'u')
		len += ft_putuint_len(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		len += ft_putx_len(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		len += ft_putchar_len('%');
	return (len);
}

/** @brief		standard printf returns -1 if forwarded invalid pointer
*				because ft_putchar_len.c returns 1,
*				I can concatenate with counters(letter_counter)
* @param str	!src is always more secure way
*				to check is it NULL then asking NULL
*				because NULL is a macro from a library
* @param ...	it accepts any number of arguments any type
*				name: Variadic function (va...)
*				to use va_list (va_start, va_end) <stdarg.h>
*				va_list args (args) servers as a bucket,
*				va_start(args, str) tells to PC start adding args after string
* @return		just length, but calling other functions which will print
**/
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
		if (str[i] == '%')
		{
			letter_counter += ft_format(args, str[i + 1]);
			i++;
		}
		else
			letter_counter += ft_putchar_len(str[i]);
		i++;
	}
	va_end(args);
	return (letter_counter);
}

	int	main(void)
{
	int	res_ft;
	int	res_std;
	void	*ptr;

	ptr = &res_ft;
	printf("=========================================\n");
	printf("           TESTING FT_PRINTF          \n");
	printf("=========================================\n\n");

	// 1. Test za %c
	printf("--- %%c (Character) ---\n");
	res_ft = ft_printf("My ftprint: [%c]\n", 'A');
	res_std = printf("std printf: [%c]\n", 'A');
	printf("Return -> My ftprint: %d | std printf: %d\n\n", res_ft, res_std);

	// 2. Test za %s
	printf("--- %%s (String) ---\n");
	res_ft = ft_printf("My ftprint: [%s]\n", "HELLO 42!");
	res_std = printf("std printf: [%s]\n", "HELLO 42!");
	printf("Return -> My ftprint: %d | std printf: %d\n\n", res_ft, res_std);

	// Zameniti linije za NULL test sa ovim:
	char *null_str = NULL;
	res_ft = ft_printf("My ftprint (NULL): [%s]\n", null_str);
	res_std = printf("std printf (NULL): [%s]\n", null_str);
	printf("Return -> My ftprint: %d | std printf: %d\n\n", res_ft, res_std);

	// 3. Test za %p
	printf("--- %%p (Pointer) ---\n");
	res_ft = ft_printf("My ftprint: [%p]\n", ptr);
	res_std = printf("std printf: [%p]\n", ptr);
	printf("Return -> My ftprint: %d | std printf: %d\n\n", res_ft, res_std);

	// 4. Test za %d i %i
	printf("--- %%d / %%i (Numbers) ---\n");
	res_ft = ft_printf("My ftprint: [%d] [%i]\n", (int)-2147483648, 2147483647);
	res_std = printf("std printf: [%d] [%i]\n", (int)-2147483648, 2147483647);
	printf("Return -> Mine  ft_print: %d | std print: %d\n\n", res_ft, res_std);

	// 5. Test za %u
	printf("--- %%u (Unsigned) ---\n");
	res_ft = ft_printf("My ftprint: [%u]\n", 4294967295U);
	res_std = printf("std printf: [%u]\n", 4294967295U);
	printf("Return -> Mine ft_printf: %d | std printf: %d\n\n", res_ft, res_std);

	// 6. Test za %x i %X
	printf("--- %%x / %%X (Hex) ---\n");
	res_ft = ft_printf("My ftprint: [%x] [%X]\n", 255, 255);
	res_std = printf("std printf: [%x] [%X]\n", 255, 255);
	printf("Return -> My ftprint: %d | std printf: %d\n\n", res_ft, res_std);

	// 7. Test za %%
	printf("--- %%%% (Procentage) ---\n");
	res_ft = ft_printf("My ftprint: [%%]\n");
	res_std = printf("std printf: [%%]\n");
	printf("Return -> My ftprint: %d | std printf: %d\n\n", res_ft, res_std);

	return (0);
}
