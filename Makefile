# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 08:51:50 by guilmira          #+#    #+#              #
#    Updated: 2021/09/23 08:19:20 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------------------------------------------------------------------------COMPILER
NAME = libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
#-g3 -fsanitize=address

#--------------------------------------------------------------------------------------------------------------LIBS
LIB			= ./libft_submodule/libft.a
INCLUDES	= -I ./0includes -I ./libft_submodule/0includes

#--------------------------------------------------------------------------------------------------------------SOURCES
SRCS = ft_printf.c ft_printf_tools_flag.c ft_printf_format.c \
ft_print_1strings.c ft_print_2pointers.c ft_print_3integers.c ft_print_4integers_unsigned.c ft_print_5hexa.c \
ft_3lib_fd.c ft_4lib_manipulatenumbers.c
OBJS = $(SRCS:.c=.o)

#--------------------------------------------------------------------------------------------------------------RULES
all: lib_submodule $(NAME)

lib_submodule:
	@make -C ./libft_submodule

%.o: %.c
	-@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIB)
	ar rcs $(NAME) $(OBJS) $(LIB)

clean:
	@rm -rf $(OBJS)
	make clean -C ./libft_submodule

fclean: clean
	@rm -rf $(NAME)
	make fclean -C ./libft_submodule

re: fclean all

.PHONY: all clean fclean re
