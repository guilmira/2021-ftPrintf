/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 08:46:55 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/20 12:14:59 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** PURPOSE : print variable on screen.
 * 1. Takes into account the details of the flag and converter.
 * 2. Prints.
 * */
static void	variable_printer(t_flag *flag, va_list x)
{
	int	lenght;

	lenght = 0;
	if (flag->signal == 'i' || flag->signal == 'd')
		print_integer(va_arg(x, int), flag);
	else if (flag->signal == 'c')
		ft_putchar_fd(va_arg(x, int), 1, flag);
	else if (flag->signal == 's')
		ft_putstr_fd(va_arg(x, char *), 1, flag);
	else if (flag->signal == 'p')
	{
		ft_putstr_fd("0x", 1, flag);
		ft_punteropositivo_fd((unsigned long long) va_arg(x, void *), "0123456789abcdef", 1, flag);
	}
	else if (flag->signal == 'u')
	{
		print_integer(va_arg(x, int), flag);
	}
	else if (flag->signal == 'x')
	{
		ft_punteropositivo_fd((unsigned long long) va_arg(x, void *), "0123456789abcdef", 1, flag);
	}
	else if (flag->signal == 'X')
	{
		ft_punteropositivo_fd((unsigned long long) va_arg(x, void *), "0123456789ABCDEF", 1, flag);
	}
	else if (flag->signal == '%') // || (flag.signal == '%' && previous == '\\')
		ft_putchar_fd('%', 1, flag);
}

/** PURPOSE : identifies the signal previous to the converter.
 * 1. Iterative on the flag whle is not converter (i. e: i, d, s, c ...)
 * 2. Registers in flag struct all the details of the flag.
 * */
static void	identify_flag(char *str, t_flag *flag, va_list x) //creo que no necceito retorno
{
	char	*precision;

	get_flags(str, flag);
	get_allignment(str, flag, x);
	precision = ft_strchr(str, '.');
	if (precision)
		get_precision(precision, flag, x);
}

/** PURPOSE : to read the string passed as an argument and identify flag.
 * 1. Reads the string.
 * 2. Stops at '%'
 * 3. Applies 'identify_flag'.
 * */
static void	read_mainstring(char **str, t_flag *flag, va_list x)
{
	int		i;
	char	*flag_string;
	char	*provisional;

	flag->signal = 0;
	i = -1;
	if (!(*str)[0])
		return ;
	while ((*str)[++i])
	{
		if ((*str)[i] == '%')
			break ;
		else
			ft_putchar_fd((*str)[i], 1, flag);
	}
	if (((*str)[i] == '%' || (*str)[i] == '\\') && ft_strchr_plus(&(*str)[i + 1], CONVERTERS))
	{
		provisional = ft_strchr_plus(&(*str)[i + 1], CONVERTERS);

		flag_string = get_flag_string(&(*str)[i + 1]);
		identify_flag(flag_string, flag, x);
		free (flag_string);
		flag->signal = provisional[0];
		advance_string(str, (ft_strchr_plus(&(*str)[i + 1], CONVERTERS) + 1));
	}
	//else
		//advance_string(str, (*str) + 1);
}

/** PURPOSE : ft_printf will recreate the behavior of printf.
 * The funct. recieves a varying number of arguments and varying types. Then prints. Iterative.
 * 1. Read argument.
 * 2. Define the flag.
 * 3. Print the argument.
 * */
int	ft_printf(const char *c, ...)
{
	va_list	x;
	t_flag	flag;
	char	*ptr;

	//flag = (*t_flag) ft_calloc(1, sizeof(*t_flag)); t_flag *flag; guardar en auxiliar, y luego lipiar aux
	init_flag(&flag);
	flag.counter = 0;
	ptr = (char *) c; //ojo, luego vasa modificar el puntero cte c. creo que no importa x ser cte.
	if (!c)
		return (0);
	va_start(x, c);
	while (flag.signal)
	{
		init_flag(&flag);
		read_mainstring(&ptr, &flag, x);
		if (flag.signal)
			variable_printer(&flag, x); //x igual hay que pasarlo por referencia ( si va_arg lo ahces en dos funciones)
	}
	va_end(x);
	//free(flag);
	return (flag.counter);
}
