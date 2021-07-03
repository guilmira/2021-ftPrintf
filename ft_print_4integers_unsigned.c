/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_4integers_unsigned.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:07:07 by guilmira          #+#    #+#             */
/*   Updated: 2021/07/03 15:44:12 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	itoa_writer_unsigned(unsigned int n, char *ptr)
{
	static int	i;

	if (n / 10 != 0)
		itoa_writer_unsigned(n / 10, ptr);
	else
		i = 0;
	ptr[i] = '0' + n % 10;
	ptr[++i] = '\0';
}

/** PURPOSE : converts integer into its string equivalent.
 * 1. Allocates memory in heap.
 * 2. Calls static function itoa-writer.
 * */
static char	*ft_itoa_unsigned(unsigned int n)
{
	char	*ptr;

	ptr = ft_calloc(ft_count_digits_unsigned(n) + 2, sizeof(char));
	if (!ptr)
		return (NULL);
	itoa_writer_unsigned(n, ptr);
	return (ptr);
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
static void	intit_int(unsigned int integer, char **str, int *lenght, t_flag *flag)
{
	if (!*str)
		*str = ft_itoa_unsigned(integer);
	*lenght = ft_strlen(*str);
	if (!integer && flag->precision && !flag->precision_total_digits)
	{
		*lenght = 0;
		flag->precision = -1;
	}
}

/** PURPOSE : prints %i and %d converter
 * Takes into account: Alignment, precision, zero filled
 * */
void	print_integer_unsigned(unsigned int integer, t_flag *flag)
{
	int		lenght;
	int		sign;
	char	*str;
	int		number_zeros;

	sign = 0;
	str = NULL;
	intit_int(integer, &str, &lenght, flag);
	number_zeros = check_zeros_n_precision(flag, lenght);
	if (!flag->precision && flag->zerofilled && flag->alignment_sign == '+')
		number_zeros = flag->zerofilled_total_digits - lenght;
	left_align_int(sign, lenght, number_zeros, flag);
	print_end(number_zeros, lenght, str, flag);
	free(str);
}
