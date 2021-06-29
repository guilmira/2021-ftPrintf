/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_2pointers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:31:24 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/29 12:32:39 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** PURPOSE : prints necessary left spaces for hexadecimal converter
 * */
void	print_left_allignment_hexa(int lenght_of_hexadecimal, t_flag *flag)
{
	while (flag->alignment_total_spaces > lenght_of_hexadecimal + 2)
	{
		ft_putchar_fd(' ', 1, flag);
		flag->alignment_total_spaces--;
	}
}

/** PURPOSE : prints necessary right spaces for hexadecimal converter
 * */
void	print_right_allignment_hexa(int lenght_of_hexadecimal, t_flag *flag)
{
	while (flag->alignment_total_spaces > lenght_of_hexadecimal + 2)
	{
		ft_putchar_fd(' ', 1, flag);
		flag->alignment_total_spaces--;
	}
}

/** PURPOSE : prints %p, %x and %X converter
 * Takes into account: Alignment
 * */
void	print_hexa(unsigned long long n, t_flag *flag)
{
	int						lenght_of_hexadecimal;
	unsigned long long		counter;

	counter = n;
	lenght_of_hexadecimal = 1;
	while (counter /= 16)
		lenght_of_hexadecimal++;
	if (flag->alignment && flag->alignment_sign == '+')
		print_left_allignment_hexa(lenght_of_hexadecimal, flag);
	ft_putstr_fd("0x", 1, flag);
	ft_positivepointer_fd(n, HEXADECIMAL, 1, flag);
	if (flag->alignment_sign == '-')
		print_right_allignment_hexa(lenght_of_hexadecimal, flag);
}
