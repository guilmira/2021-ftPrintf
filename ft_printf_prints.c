/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prints.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:07:07 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/22 15:04:34 by guilmira         ###   ########.fr       */
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

/** PURPOSE : prints %i and %d converter
 * Takes into account: Alignment, precision
 * */
void	print_integer(int integer, t_flag *flag)
{
	int		lenght;
	int		sign;
	char	*str;
	int		i;

	i = 0;
	sign = 0;
	if (integer < 0)
	{
		sign++;
		integer *= -1;
	}
	str = ft_itoa(integer);
	lenght = ft_strlen(str);
	if (flag->alignment && flag->alignment_sign == '+')
	{
		while (flag->alignment_total_spaces > lenght)
		{
			ft_putchar_fd(' ', 1, flag);
			flag->alignment_total_spaces--;
		}
	}
	if (sign == 1)
	{
		ft_putchar_fd('-', 1, flag);
		sign++;
	}
	if (flag->precision_total_digits > lenght)
	{
		while (flag->precision_total_digits - lenght > 0)
		{
			ft_putchar_fd('0', 1, flag);
			flag->precision_total_digits--;
		}
		ft_putstr_fd(str, 1, flag);
	}
	else if (flag->precision && !(flag->precision_total_digits))
	{
		;
	}
	else
		ft_putstr_fd(str, 1, flag);
	if (flag->alignment && flag->alignment_sign == '-')
	{
		while (flag->alignment_total_spaces > lenght)
		{
			ft_putchar_fd(' ', 1, flag);
			flag->alignment_total_spaces--;
		}
	}
	free(str);


}
