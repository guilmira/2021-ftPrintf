/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:53:22 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/30 12:56:49 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** PURPOSE : Init struct. Does not intialize counter */
void	init_flag(t_flag *flag)
{
	flag->signal = '9';
	flag->zerofilled = 0;
	flag->zerofilled_total_digits = 0;
	flag->alignment = 0;
	flag->alignment_sign = '+';
	flag->alignment_total_spaces = 0;
	flag->precision = 0;
	flag->precision_total_digits = 0;
	flag->invisible_plus_sign = 0;
	flag->plus_sign = 0;
}

/** PURPOSE : prints integer and unsigned integer left part */
void	left_align_int(int sign, int lenght, int number_zeros, t_flag *flag)
{
	if (flag->alignment && flag->alignment_sign == '+')
	{
		if (sign)
			flag->alignment_total_spaces--;
		while (flag->alignment_total_spaces-- > (lenght + number_zeros))
			ft_putchar_fd(' ', 1, flag);
	}
}

/** PURPOSE : print end part for %d, %i and %u
 * Used in functions print_integer and print_unsigned.
 */
void	print_end(int number_zeros, int lenght, char *str, t_flag *flag)
{
	while (number_zeros > 0)
	{
		ft_putchar_fd('0', 1, flag);
		number_zeros--;
		lenght++;
	}
	if ((!flag->precision || (flag->precision != -1)))
		ft_putstr_fd(str, 1, flag);
	if (flag->alignment && flag->alignment_sign == '-')
		while (flag->alignment_total_spaces-- - lenght > 0)
			ft_putchar_fd(' ', 1, flag);
}

/** PURPOSE : to output number of zeros
 *	1. Check all the conditions in case zerofilled exists
 * */
int	check_flag_zerofilled(t_flag *flag, int lenght)
{
	if (flag->zerofilled_total_digits < 0)
	{
		flag->zerofilled_total_digits *= -1;
		flag->alignment_sign = '-';
	}
	if (flag->zerofilled_total_digits > flag->precision_total_digits)
	{
		flag->alignment = 1;
		flag->alignment_total_spaces = flag->alignment_total_spaces + \
		(flag->zerofilled_total_digits);
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
