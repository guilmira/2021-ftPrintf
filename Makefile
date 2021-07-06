# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 08:51:50 by guilmira          #+#    #+#              #
#    Updated: 2021/07/06 08:37:00 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_tools_flag.c ft_printf_format.c \
ft_print_1strings.c ft_print_2pointers.c ft_print_3integers.c ft_print_4integers_unsigned.c ft_print_5hexa.c \
ft_1lib_memorybasics.c ft_2lib_complexstrings.c ft_3lib_fd.c ft_4lib_manipulatenumbers.c
SRCS_BONUS = ft_printf.c ft_printf_tools_flag.c ft_printf_format.c\
ft_print_1strings.c ft_print_2pointers.c ft_print_3integers.c ft_print_4integers_unsigned.c ft_print_5hexa.c \
ft_1lib_memorybasics.c ft_2lib_complexstrings.c ft_3lib_fd.c ft_4lib_manipulatenumbers.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
normi:
	norminette $(SRCS)
clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

bonus: all

.PHONY: all re m clean fclean bonus
