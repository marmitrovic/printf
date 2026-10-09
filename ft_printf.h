/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 09:09:10 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/25 09:09:13 by mmitrovi         ###   ########.fr       */
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