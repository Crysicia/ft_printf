# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 11:22:32 by lpassera          #+#    #+#              #
#    Updated: 2020/12/05 17:58:45 by lpassera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR 			= ar rc
CC			= gcc
CFLAGS 		= -Wall -Wextra -Werror
RM 			= rm -f
NAME 		= libftprintf.a
HEADER 		= includes/nomallocs.h

SRCS 		= srcs/nomallocs.c \
			  srcs/pf_print_int.c \
			  srcs/ft_math.c \
			  srcs/ft_string.c \
			  srcs/ft_conversion.c \
			  srcs/pf_parse_directive.c \
			  srcs/pf_print_char.c \

OBJS 		= $(SRCS:.c=.o)
BONUS_OBJS 	= $(BONUS_SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

test: $(OBJS)
	gcc srcs/main_char.c $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean
