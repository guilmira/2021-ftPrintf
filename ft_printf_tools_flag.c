/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:53:22 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/30 11:25:25 by guilmira         ###   ########.fr       */
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

/** PURPOSE : prints integer left part */
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
