# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 08:51:50 by guilmira          #+#    #+#              #
#    Updated: 2021/07/04 14:09:34 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = main.c ft_printf.c ft_printf_tools_flag.c \
ft_print_1strings.c ft_print_2pointers.c ft_print_3integers.c ft_print_4integers_unsigned.c ft_print_5hexa.c \
ft_printf_format.c \
ft_1lib_memorybasics.c ft_2lib_complexstrings.c ft_3lib_fd.c ft_4lib_manipulatenumbers.c
SRCS_BONUS = ft_printf.c ft_printf_tools_flag.c ft_printf_prints.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
m:
	gcc -Wall -Wextra -Werror $(SRCS) && ./a.out
s:
	gcc  $(SRCS) -fsanitize=address
deb:
	gcc -g -Wall -Wextra -Werror $(SRCS)
k:
	gcc $(SRCS) && ./a.out
kdeb:
	gcc -g $(SRCS) && ./a.out

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

normi:
	norminette $(SRCS)

re: fclean all

.PHONY: all re m clean fclean bonus
