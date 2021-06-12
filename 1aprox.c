/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 08:46:55 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/12 10:56:50 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "./libft/libft.h"

int	ft_printf(const char *c, ...)
{
	va_list	x;
	int		i;
	int		signal;
	int		integer;
	char character;
	char *string;

	integer = 0;
	i = -1;
	va_start(x, c);
	while (c[++i])
	{
		if (c[i] =='%' && c[i + 1] == 'i')
			signal = 1;
		if (c[i] =='%' && c[i + 1] == 'c')
			signal = 2;
		if (c[i] =='%' && c[i + 1] == 's')
			signal = 3;
	}
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
	va_end(x);
	return (0);


}


int	main(void)
{
	ft_printf("%c", 'Z');
	return (0);
}
