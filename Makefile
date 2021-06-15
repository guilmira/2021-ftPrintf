# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 08:51:50 by guilmira          #+#    #+#              #
#    Updated: 2021/06/15 16:17:11 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libtfprintf.a

SRCS = main.c ft_printf.c ft_printf_utiles_flag.c
SRCS_BONUS = ft_printf.c ft_printf_utiles_flag.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

#$(SRCS): $(OBJS)
	#gcc -Wall -Wextra -Werror libft.a -o $(NAME) $(OBJS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

m:
	gcc -Wall -Wextra -Werror ./libft/libft.a $(SRCS) && ./a.out
deb:
	gcc -g -Wall -Wextra -Werror ./libft/libft.a $(SRCS)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)
	#rm ./a.out

re: fclean all

.PHONY: all re m clean fclean bonus
