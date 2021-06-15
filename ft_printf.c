/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 08:46:55 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/15 16:20:14 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	variable_printer(t_flag flag, va_list x)
{
	int	integer;
	int	lenght;

	lenght = 0;
	if (flag.signal == 'i' || flag.signal == 'd')
	{
		integer = va_arg(x, int);
		lenght = number_digits(integer);
		while (lenght++ < flag.total_alignment_spaces)
			ft_putchar_fd(' ', 1);
		ft_putnbr_fd(integer, 1);
	}
	else if (flag.signal == 'c')
		ft_putchar_fd(va_arg(x, int), 1);
	else if (flag.signal == 's')
		ft_putstr_fd(va_arg(x, char *), 1);
	else if (flag.signal == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_fd((unsigned long long) va_arg(x, void *), "0123456789abcdef", 1);
	}
	else if (flag.signal == 'u')
	{
	}
	else if (flag.signal == 'x')
	{
	}
	else if (flag.signal == 'X')
	{
	}
	else if (flag.signal == '%') // || (flag.signal == '%' && previous == '\\')
		ft_putchar_fd('%', 1);
}

static t_flag	identify_flag(char **str, t_flag flag)
{
	int		i;
	char	*aux;
	int		counter_allignment;

	i = -1;
	counter_allignment = 0;
	aux = *str;
	while (check_ifis_converter((*str)[++i]) != 1)
	{
		if (ft_isdigit((*str)[i]) && counter_allignment == 0)
		{
			flag.total_alignment_spaces = allignment(&(*str)[i]);
			counter_allignment++;
		}
		if ((*str)[i] == '+')
			flag.plus_sign = 1;
		if ((*str)[i] == ' ')
			flag.invisible_plus_sign = 1;
		if ((*str)[i] == '0')
			flag.zerofilled = 1;
		if ((*str)[i] == '-')
			flag.alignment_sign = 1;
		aux++;
	}
	flag.signal	= (*str)[i];
	*str = ++aux;
	return (flag);
}

static t_flag	read_mainstring(char **str, t_flag flag)
{
	int		i;
	char	*aux;

	flag.signal = 0;
	i = -1;
	if (!(*str)[0])
	{
		flag.signal = 0;
		return (flag);
	}
	aux = *str;
	while ((*str)[++i])
	{
		aux++;
		if ((*str)[i] == '%')
			break ;
		else
			ft_putchar_fd((*str)[i], 1);
	}
	if ((*str)[i] == '%' || (*str)[i] == '\\')
	{
		*str = aux;
		flag = identify_flag(str, flag);
	}
	return (flag);
}

int	ft_printf(const char *c, ...)
{
	va_list	x;
	char	*ptr;
	t_flag	flag;

	init_flag(&flag);
	ptr = (char *) c; //ojo, luego vasa modificar el puntero cte c. creo que no importa x ser cte.
	if (!c)
		return (0);
	va_start(x, c);
	while (flag.signal)
	{
		init_flag(&flag);
		flag = read_mainstring(&ptr, flag);
		if (flag.signal)
		{
			variable_printer(flag, x);
		}
	}
	va_end(x);
	return (0);
}
