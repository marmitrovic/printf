# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/25 09:08:30 by mmitrovi          #+#    #+#              #
#    Updated: 2026/09/25 09:08:31 by mmitrovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS = ft_printf.c \
ft_putchar_len.c \
ft_putstr_len.c \
ft_putnbr_len.c \
ft_putuint_len.c \
ft_putx_len.c \
ft_putp_len.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re