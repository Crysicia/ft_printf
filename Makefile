# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 11:22:32 by lpassera          #+#    #+#              #
#    Updated: 2020/12/08 23:21:37 by lpassera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR 			= ar rc
CC			= gcc
CFLAGS 		= -Wall -Wextra -Werror
RM 			= rm -f
NAME 		= libftprintf.a
HEADERS 	= includes

SRCS 		= ft_printf.c \
			  srcs/ft_math.c \
			  srcs/ft_string.c \
			  srcs/ft_conversion.c \
			  srcs/pf_parse_directive.c \
			  srcs/pf_print_int.c \
			  srcs/pf_print_char.c \
			  srcs/pf_print_string.c \
			  srcs/pf_print_unsigned.c \
			  srcs/pf_print_hex.c \
			  srcs/pf_print_addr.c \
			  srcs/pf_print_percent.c \

OBJS 		= $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
