/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utiles_flag.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:53:22 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/22 12:35:22 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_ifis_converter(char c)
{
	return (c == 'i' || c == 'd' || c == 'c' \
	|| c == 's' || c == 'p' || c == 'u' \
	|| c == 'x' || c == 'X' || c == '%');
}

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
