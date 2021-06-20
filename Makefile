# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 08:51:50 by guilmira          #+#    #+#              #
#    Updated: 2021/06/19 10:52:35 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = main.c ft_printf.c ft_printf_utiles_flag.c ft_printf_prints.c \
ft_lib1.c ft_lib2.c ft_lib3.c
SRCS_BONUS = ft_printf.c ft_printf_utiles_flag.c ft_printf_prints.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(SRCS): $(OBJS)
	gcc -Wall -Wextra -Werror $(SRCS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
m:
	gcc -Wall -Wextra -Werror $(SRCS) && ./a.out
#m:
	#gcc -Wall -Wextra -Werror ./libft_submodulo/libft.a $(SRCS) && ./a.out
deb:
	gcc -g -Wall -Wextra -Werror $(SRCS)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)
	#rm ./a.out

re: fclean all

.PHONY: all re m clean fclean bonus
