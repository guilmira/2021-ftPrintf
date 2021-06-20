/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prints.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:07:07 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/20 11:01:09 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
