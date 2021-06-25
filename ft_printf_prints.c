/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prints.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:07:07 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/25 11:16:11 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** PURPOSE : prints %c converter
 * Takes into account: Alignment
 * */
void	print_char(int c, t_flag *flag)
{
	if (flag->alignment && flag->alignment_sign == '+')
	{
		flag->alignment_total_spaces--;
		while (flag->alignment_total_spaces)
		{
			ft_putchar_fd(' ', 1, flag);
			flag->alignment_total_spaces--;
		}
	}
	ft_putchar_fd(c, 1, flag);
	if (flag->alignment && flag->alignment_sign == '-')
	{
		flag->alignment_total_spaces--;
		while (flag->alignment_total_spaces)
		{
			ft_putchar_fd(' ', 1, flag);
			flag->alignment_total_spaces--;
		}
	}
}

/** PURPOSE : prints %s converter
 * Takes into account: Alignment, precision
 * */
void print_string(char *str, t_flag *flag)
{
	int	lenght;
	int	i;

	i = 0;
	if (!str)
		lenght = 0;
	else
		lenght = ft_strlen(str);
	if (flag->precision && flag->precision_total_digits < lenght)
		lenght = flag->precision_total_digits;
	if (flag->alignment && flag->alignment_sign == '+')
	{
		while (flag->alignment_total_spaces > lenght)
		{
			ft_putchar_fd(' ', 1, flag);
			flag->alignment_total_spaces--;
		}
	}
	if (!(flag->precision))
		ft_putstr_fd(str, 1, flag);
	else
	{
		while (flag->precision_total_digits > 0)
		{
			if (str[i])
			{
				ft_putchar_fd(str[i], 1, flag);
				i++;
			}
			flag->precision_total_digits--;
		}
	}

	if (flag->alignment && flag->alignment_sign == '-')
	{
		while (flag->alignment_total_spaces > lenght)
		{
			ft_putchar_fd(' ', 1, flag);
			flag->alignment_total_spaces--;
		}
	}
}

/** PURPOSE : prints %p, %x and %X converter
 * Takes into account: Alignment
 * */
void	print_hexa(unsigned long long n, t_flag *flag)
{
	ft_putstr_fd("0x", 1, flag);
	ft_positivepointer_fd(n, "0123456789abcdef", 1, flag);
}

/** PURPOSE : to output number of zeros that must be printed
 *	1. Only enters if precision exists.
 *	2. Check all the conditions for zerofilled and precision
 * */
int	check_zeros_n_precision(t_flag *flag, int lenght)
{
	if (flag->zerofilled)
	{
		if (flag->zerofilled_total_digits < 0)
		{
			flag->zerofilled_total_digits *= -1;
			flag->alignment_sign = '-';
		}
		if (flag->zerofilled_total_digits > flag->precision_total_digits)
		{
			flag->alignment = 1;
			flag->alignment_total_spaces = flag->alignment_total_spaces + (flag->zerofilled_total_digits);
			if (flag->precision_total_digits > lenght)
				return (flag->precision_total_digits - lenght);
			else
				return (0);
		}
		else
		{
			if (flag->precision_total_digits > lenght)
				return (flag->precision_total_digits - lenght);
			else
				return (0);
		}
	}
	else
	{
		if ((flag->precision_total_digits - lenght) >= 0)
			return (flag->precision_total_digits - lenght);
		else
			return (0);
	}
}

int	intitialize_int_print(int integer, char **str, int *lenght, t_flag *flag)
{
	int sign;

	sign = 0;
	if (integer == -2147483648)
	{
		sign++;
		*str = ft_strdup("2147483648");
	}
	else if (integer < 0)
	{
		sign++;
		integer *= -1;
	}
	if (!*str)
		*str = ft_itoa(integer);
	*lenght = ft_strlen(*str);
	if (!integer && flag->precision && !flag->precision_total_digits)
	{
		*lenght = 0;
		flag->precision = -1;
	}
	return (sign);
}

/** PURPOSE : prints %i and %d converter
 * Takes into account: Alignment, precision, zero filled
 * */
void	print_integer(int integer, t_flag *flag)
{
	int		lenght;
	int		sign;
	char	*str;
	int		number_zeros;

	str = NULL;
	sign = intitialize_int_print(integer, &str, &lenght, flag);
	number_zeros = check_zeros_n_precision(flag, lenght);
	if (!flag->precision && flag->zerofilled && flag->alignment_sign == '+')
		number_zeros = flag->zerofilled_total_digits - lenght;
	if (flag->alignment && flag->alignment_sign == '+')
	{
		if (sign == 1)
			flag->alignment_total_spaces--;
		while (flag->alignment_total_spaces > (lenght + number_zeros))
		{
			ft_putchar_fd(' ', 1, flag);
			flag->alignment_total_spaces--;
		}
	}
	if (sign == 1)
	{
		ft_putchar_fd('-', 1, flag);
		if (flag->alignment_total_spaces > 0)
			flag->alignment_total_spaces--;
		sign++;
	}
	while (number_zeros > 0)
	{
		ft_putchar_fd('0', 1, flag);
		number_zeros--;
		lenght++; //para despues tener las cifras correctas
	}
	if ((!flag->precision || (flag->precision != -1)))
		ft_putstr_fd(str, 1, flag);
	if (flag->alignment && flag->alignment_sign == '-')
	{
		while (flag->alignment_total_spaces - lenght > 0)
		{
			ft_putchar_fd(' ', 1, flag);
			flag->alignment_total_spaces--;
		}
	}
	free(str);


}
