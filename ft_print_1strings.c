/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_1strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:35:16 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/23 08:17:28 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** PURPOSE : to print number of zeros
 *	1. Check all the conditions for zerofilled */
static void	print_zeros_char(t_flag *flag)
{
	int	number_zeros;

	number_zeros = flag->zerofilled_total_digits - 1;
	if (flag->zerofilled)
	{
		while (number_zeros > 0)
		{
			pf_putchar_fd('0', 1, flag);
			number_zeros--;
		}
	}
}

/** PURPOSE : prints %c converter
 * Takes into account: Alignment */
void	print_char(int c, t_flag *flag)
{
	print_zeros_char(flag);
	if (flag->alignment && flag->alignment_sign == '+')
	{
		flag->alignment_total_spaces--;
		while (flag->alignment_total_spaces)
		{
			pf_putchar_fd(' ', 1, flag);
			flag->alignment_total_spaces--;
		}
	}
	pf_putchar_fd(c, 1, flag);
	if (flag->alignment && flag->alignment_sign == '-')
	{
		flag->alignment_total_spaces--;
		while (flag->alignment_total_spaces)
		{
			pf_putchar_fd(' ', 1, flag);
			flag->alignment_total_spaces--;
		}
	}
}

/** PURPOSE : prints %s converter
 * Takes into account: Alignment, precision */
void	print_string(char *str, t_flag *flag)
{
	int	lenght;
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	lenght = ft_strlen(str);
	if (flag->precision && flag->precision_total_digits < lenght)
		lenght = flag->precision_total_digits;
	if (flag->alignment && flag->alignment_sign == '+')
		while (flag->alignment_total_spaces-- > lenght)
			pf_putchar_fd(' ', 1, flag);
	if (!(flag->precision))
		pf_putstr_fd(str, 1, flag);
	else
		while (flag->precision_total_digits-- > 0)
			if (str[i])
				pf_putchar_fd(str[i++], 1, flag);
	if (flag->alignment && flag->alignment_sign == '-')
		while (flag->alignment_total_spaces-- > lenght)
			pf_putchar_fd(' ', 1, flag);
}
