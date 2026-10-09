/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:24:10 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 18:24:11 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_putchar_len(char c);
int	ft_putstr_len(char *s);
int	ft_putnbr_len(int n);
int	ft_putuint_len(unsigned int n);
int	ft_putx_len(unsigned int n, char format);
int	ft_putp_len(unsigned long ptr);
#endif