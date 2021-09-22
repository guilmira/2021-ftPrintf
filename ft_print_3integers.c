/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_3integers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:07:07 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/22 12:19:26 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	analyze_sign(int number_zeros, t_flag *flag)
{
	ft_putchar_fd('-', 1, flag);
	if (flag->alignment_total_spaces > 0)
		flag->alignment_total_spaces--;
	if (number_zeros > 0 \
	&& flag->precision_total_digits <= flag->alignment_total_spaces \
	&& flag->precision_total_digits < flag->zerofilled_total_digits)
		number_zeros--;
	return (number_zeros);
}

/** PURPOSE : to output number of zeros that must be printed
 *	1. Check all the conditions for zerofilled and precision */
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

/** PURPOSE : evaluates integer and converts it to string. */
static int	init_int(int integer, char **str, int *lenght, t_flag *flag)
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

/** PURPOSE : prints %i and %d converter
 * Takes into account: Alignment, precision, zero filled */
void	print_integer(int integer, t_flag *flag)
{
	int		lenght;
	int		sign;
	char	*str;
	int		number_zeros;

	str = NULL;
	sign = init_int(integer, &str, &lenght, flag);
	number_zeros = check_zeros_n_precision(flag, lenght);
	if (!flag->precision && flag->zerofilled && flag->alignment_sign == '+')
		number_zeros = flag->zerofilled_total_digits - lenght;
	left_align_int(sign, lenght, number_zeros, flag);
	if (sign)
		number_zeros = analyze_sign(number_zeros, flag);
	if ((flag->plus_sign || flag->invisible_sign) \
	&& (flag->signal == 'i' || flag->signal == 'd') \
	&& flag->precision_total_digits <= lenght && !sign)
		number_zeros--;
	if ((flag->plus_sign || flag->invisible_sign) && !sign)
		flag->alignment_total_spaces--;
	print_end(number_zeros, lenght, str, flag);
	free(str);
}
