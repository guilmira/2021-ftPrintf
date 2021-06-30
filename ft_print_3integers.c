/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_3integers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:07:07 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/30 11:24:32 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** PURPOSE : to output number of zeros
 *	1. Check all the conditions in case zerofilled exists
 * */
static int	check_flag_zerofilled(t_flag *flag, int lenght)
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

/** PURPOSE : to output number of zeros that must be printed
 *	1. Check all the conditions for zerofilled and precision
 * */
static int	check_zeros_n_precision(t_flag *flag, int lenght)
{
	if (flag->zerofilled)
		return (check_flag_zerofilled(flag, lenght));
	else
	{
		if ((flag->precision_total_digits - lenght) >= 0)
			return (flag->precision_total_digits - lenght);
		else
			return (0);
	}
}

/** PURPOSE : evaluates integer and converts it to string.
 * */
int	intit_int(int integer, char **str, int *lenght, t_flag *flag)
{
	int	sign;

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

static void	print_end(int number_zeros, int lenght, char *str, t_flag *flag)
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
	sign = intit_int(integer, &str, &lenght, flag);
	number_zeros = check_zeros_n_precision(flag, lenght);
	if (!flag->precision && flag->zerofilled && flag->alignment_sign == '+')
		number_zeros = flag->zerofilled_total_digits - lenght;
	left_align_int(sign, lenght, number_zeros, flag);
	if (sign)
	{
		ft_putchar_fd('-', 1, flag);
		if (flag->alignment_total_spaces > 0)
			flag->alignment_total_spaces--;
		if (number_zeros > 0 \
		&& flag->precision_total_digits < flag->alignment_total_spaces \
		&& flag->precision_total_digits < flag->zerofilled_total_digits)
			number_zeros--;
	}
	print_end(number_zeros, lenght, str, flag);
	free(str);
}
