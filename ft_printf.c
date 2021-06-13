/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 08:46:55 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/13 17:29:04 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	identify_flag(char c)
{
	int signal;

	signal = 0;
	if (c == 'i')
		signal = 1;
	else if (c == 'c')
		signal = 2;
	else if (c == 's')
		signal = 3;
	else if (c == 'p')
		signal = 4;
	else
		signal = 0;
	return (signal);
}

void	variable_printer(int signal, va_list x)
{
	if (signal == 1)
		ft_putnbr_fd(va_arg(x, int), 1);
	if (signal == 2)
		ft_putchar_fd(va_arg(x, int), 1);
	if (signal == 3)
		ft_putstr_fd(va_arg(x, char *), 1);
	if (signal == 4)
	{
		//convert hexa pointer to int, then feed int
		ft_putnbr_base_fd((int) va_arg(x, void *), "0123456789ABCDEF", 1);
	}
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
	return (signal);
}

int	ft_printf(const char *c, ...)
{
	va_list	x;
	int		signal;
	char	*ptr;

	signal = -1;
	ptr = (char *) c;
	if (!c)
		return (0);
	va_start(x, c);
	while (signal)
	{
		signal = read_mainstring(&ptr);
		if (signal != 0)
			variable_printer(signal, x);
	}
	va_end(x);
	return (0);
}
//#include <stdio.h>
int	main(void)
{
	int i;
	i = 50;
	ft_printf("char %c int %i  el string %s y el punero %p", 'Z', i, "finito", &i);
	//printf("\n%p\n", &i);
	return (0);
}
