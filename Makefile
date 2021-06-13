# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 08:51:50 by guilmira          #+#    #+#              #
#    Updated: 2021/06/13 16:57:55 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libtfprintf.a

SRCS = ft_printf.c
#./libft/ft_putnbr_fd.c ./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c ./libft/ft_strlen.c
SRCS_BONUS = ft_printf.c

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
