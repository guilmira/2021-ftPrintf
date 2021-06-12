/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 08:46:55 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/12 12:28:40 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "./libft/libft.h"

int	identify_flag(char c)
{
	int signal;

	signal = 0;
	if (c == 'i')
		signal = 1;
	if (c == 'c')
		signal = 2;
	if (c == 's')
		signal = 3;
	return (signal);
}

int read_mainstring(char **str)
{
	int	i;
	int	signal;
	char *aux;

	signal = -1;
	i = -1;
	if (!(*str)[0])
		return (0);
	aux = *str;
	while ((*str)[++i])
	{
		aux++;
		if ((*str)[i] == '%')
		{
			if (i > 0)
				if((*str)[i - 1] != '\\')
					break;
		}
		else
			ft_putchar_fd((*str)[i], 1);
	}
	if ((*str)[i] == '%')
	{
			if (i > 0)
				if((*str)[i - 1] != '\\')
					signal = identify_flag((*str)[i + 1]);
	}
	*str = ++aux;
	if (((*str)[i]))
		return(0);
	return (signal);
}

int	ft_printf(const char *c, ...)
{
	va_list	x;
	int		signal;
	char	*ptr;

	int		integer;
	char character;
	char *string;

	integer = 0;
	signal = -1;
	ptr = (char *) c;
	if (!c)
		return (0);
	va_start(x, c);

	while (signal)
	{
		signal = read_mainstring(&ptr);
		if (signal != 0)
		{
			if (signal == 1)
	{
		integer = va_arg(x, int);
		ft_putnbr_fd(integer, 1);
	}
	if (signal == 2)
	{
		character = va_arg(x, int);
		ft_putchar_fd(character, 1);
	}
	if (signal == 3)
	{
		string = va_arg(x, char *);
		ft_putstr_fd(string, 1);
	}
		}
	}


	va_end(x);
	return (0);


}


int	main(void)
{
	ft_printf("char %c ", 'Z');
	return (0);
}
