/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_5hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:07:07 by guilmira          #+#    #+#             */
/*   Updated: 2021/07/05 14:52:08 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	itoa_writer_base(unsigned int n, char *ptr, char *base)
{
	static int	i;

	if (n / 16)
		itoa_writer_base(n / 16, ptr, base);
	else
		i = 0;
	ptr[i] = base[n % 16];
	ptr[++i] = '\0';
}

/** PURPOSE : converts integer into its string equivalent.
 * 1. Allocates memory in heap.
 * 2. Calls static function itoa-writer.
 * */
static char	*ft_itoa_base(unsigned int n, char *base)
{
	char	*ptr;

	ptr = ft_calloc(ft_count_digits_unsigned(n) + 2, sizeof(char));
	if (!ptr)
		return (NULL);
	itoa_writer_base(n, ptr, base);
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
static char	*init_hexa(unsigned int hexa, int *lenght, t_flag *flag, char *base)
{
	char	*str;

	str = ft_itoa_base(hexa, base);
	*lenght = ft_strlen(str);
	if (!hexa && flag->precision && !flag->precision_total_digits)
	{
		*lenght = 0;
		flag->precision = -1;
	}
	return (str);
}

/** PURPOSE : prints %i and %d converter
 * Takes into account: Alignment, precision, zero filled
 * */
void	print_hexa(unsigned int hexa, t_flag *flag, char *base, char *prefix)
{
	int		lenght;
	int		sign;
	char	*str;
	int		number_zeros;

	if (flag->alternative && flag->alignment_sign == '+' && hexa)
		flag->alignment_total_spaces -= 2;
	sign = 0;
	str = init_hexa(hexa, &lenght, flag, base);
	number_zeros = check_zeros_n_precision(flag, lenght);
	if (!flag->precision && flag->zerofilled && flag->alignment_sign == '+')
		number_zeros = flag->zerofilled_total_digits - lenght;
	left_align_int(sign, lenght, number_zeros, flag);
	if (flag->alternative && hexa)
	{
		ft_putstr_fd(prefix, 1, flag);
		if (flag->precision_total_digits < flag->zerofilled_total_digits)
		{
			number_zeros -= 2;

		}
		flag->alignment_total_spaces -= 2;
	}
	print_end(number_zeros, lenght, str, flag);
	free(str);
}
