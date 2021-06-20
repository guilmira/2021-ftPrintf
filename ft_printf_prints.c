/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prints.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:07:07 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/19 12:57:59 by guilmira         ###   ########.fr       */
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
	if (flag->total_alignment_spaces < 0)
	{
		flag->alignment_sign = '-';
		flag->total_alignment_spaces = flag->total_alignment_spaces * -1;
	}
	if (lenght >= flag->precision_digits && lenght >= flag->total_alignment_spaces && lenght >= flag->zerofilled)
		;
	else if (flag->precision_digits > lenght && flag->precision_digits >= flag->total_alignment_spaces)
		while (lenght++ < flag->precision_digits)
				ft_putchar_fd('0', 1, flag);
	else if (flag->total_alignment_spaces > flag->precision_digits && flag->total_alignment_spaces > lenght)
	{
		if (flag->alignment_sign == '-')
		{
			change++;
			while (lenght++ < flag->precision_digits)
				ft_putchar_fd('0', 1, flag);
			ft_putnbr_fd(integer, 1, flag);
			while (lenght++ <= flag->total_alignment_spaces)
				ft_putchar_fd(' ', 1, flag);
		}
		else
		{
			while (flag->total_alignment_spaces > flag->precision_digits && flag->total_alignment_spaces-- > lenght)
				ft_putchar_fd(' ', 1, flag);
			while (lenght++ < flag->precision_digits)
				ft_putchar_fd('0', 1, flag);
		}
	}
	else if (flag->zerofilled)
		while (lenght++ < flag->zerofilled)
				ft_putchar_fd('0', 1, flag);
	else
		while (lenght++ < flag->total_alignment_spaces)
			ft_putchar_fd(' ', 1, flag);
	if (!change && flag->precision_digits >= 0)
		ft_putnbr_fd(integer, 1, flag);
}
