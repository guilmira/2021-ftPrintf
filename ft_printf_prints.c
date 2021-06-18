/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prints.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:07:07 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/18 11:09:06 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_integer(int integer, t_flag flag)
{
	int	lenght;
	int	change;

	change  = 0;
	lenght = number_digits(integer);
	if (lenght >= flag.precision_digits && lenght >= flag.total_alignment_spaces)
		;
	else if (flag.precision_digits > lenght && flag.precision_digits >= flag.total_alignment_spaces)
		while (lenght++ < flag.precision_digits)
				ft_putchar_fd('0', 1);
	else if (flag.total_alignment_spaces > flag.precision_digits && flag.total_alignment_spaces > lenght)
	{
		if (flag.alignment_sign == '-')
		{
			change++;
			while (lenght++ < flag.precision_digits)
				ft_putchar_fd('0', 1);
			ft_putnbr_fd(integer, 1);
			while (lenght++ <= flag.total_alignment_spaces)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while (flag.total_alignment_spaces > flag.precision_digits && flag.total_alignment_spaces-- > lenght)
				ft_putchar_fd(' ', 1);
			while (lenght++ < flag.precision_digits)
				ft_putchar_fd('0', 1);
		}
	}
	else
		while (lenght++ < flag.total_alignment_spaces)
			ft_putchar_fd(' ', 1);
	if (!change)
		ft_putnbr_fd(integer, 1);
}
