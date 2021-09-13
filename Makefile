# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 08:51:50 by guilmira          #+#    #+#              #
#    Updated: 2021/09/13 16:56:59 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------------------------------------------------------------------------COMPILER
NAME = libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
#-g3 -fsanitize=address
#--------------------------------------------------------------------------------------------------------------SOURCES
SRCS = ft_printf.c ft_printf_tools_flag.c ft_printf_format.c \
ft_print_1strings.c ft_print_2pointers.c ft_print_3integers.c ft_print_4integers_unsigned.c ft_print_5hexa.c \
ft_1lib_memorybasics.c ft_2lib_complexstrings.c ft_3lib_fd.c ft_4lib_manipulatenumbers.c
OBJS = $(SRCS:.c=.o)
#--------------------------------------------------------------------------------------------------------------RULES

all: $(NAME)

%.o: %.c
	-@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

bonus: all

.PHONY: all re m clean fclean bonus
