/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prints.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:07:07 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/21 16:30:52 by guilmira         ###   ########.fr       */
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

/** PURPOSE : prints %i and % d converter
 * Takes into account: Alignment
 * */
void	print_integer(int integer, t_flag *flag)
{
	int	lenght;
	int	change;

	change  = 0;
	lenght = number_digits(integer);
	if (integer < 0)
	{
		integer *= -1;
		ft_putchar_fd('-', 1, flag);
	}
	if (flag->alignment_total_spaces < 0)
	{
		flag->alignment_sign = '-';
		flag->alignment_total_spaces = flag->alignment_total_spaces * -1;
	}
	if (lenght >= flag->precision_total_digits && lenght >= flag->alignment_total_spaces && lenght >= flag->zerofilled)
		;
	else if (flag->precision_total_digits > lenght && flag->precision_total_digits >= flag->alignment_total_spaces)
		while (lenght++ < flag->precision_total_digits)
				ft_putchar_fd('0', 1, flag);
	else if (flag->alignment_total_spaces > flag->precision_total_digits && flag->alignment_total_spaces > lenght)
	{
		if (flag->alignment_sign == '-')
		{
			change++;
			while (lenght++ < flag->precision_total_digits)
				ft_putchar_fd('0', 1, flag);
			ft_putnbr_fd(integer, 1, flag);
			while (lenght++ <= flag->alignment_total_spaces)
				ft_putchar_fd(' ', 1, flag);
		}
		else
		{
			while (flag->alignment_total_spaces > flag->precision_total_digits && flag->alignment_total_spaces-- > lenght)
				ft_putchar_fd(' ', 1, flag);
			while (lenght++ < flag->precision_total_digits)
				ft_putchar_fd('0', 1, flag);
		}
	}
	else if (flag->zerofilled)
		while (lenght++ < flag->zerofilled)
				ft_putchar_fd('0', 1, flag);
	else
		while (lenght++ < flag->alignment_total_spaces)
			ft_putchar_fd(' ', 1, flag);
	if (!change && flag->precision_total_digits >= 0)
		ft_putnbr_fd(integer, 1, flag);
}
