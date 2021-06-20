/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utiles_flag.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:53:22 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/19 12:12:31 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_ifis_converter(char c)
{
	return (c == 'i' || c == 'd' || c == 'c' \
	|| c == 's' || c == 'p' || c == 'u' \
	|| c == 'x' || c == 'X' || c == '%');
}

void	init_flag(t_flag *flag)
{
	flag->signal = '9';
	flag->alignment_sign = '+';
	flag->total_alignment_spaces = 0;
	flag->precision_digits = 0;
	flag->invisible_plus_sign = 0;
	flag->plus_sign = 0;
	flag->zerofilled = 0;
}

int	get_number_from_string(char *number)
{
	int		i;
	int		lenght;
	int		value;
	char	*number_string;

	i = -1;
	lenght = 0;
	value = 0;
	while (ft_isdigit(number[++i]))
		lenght++;
	number_string = ft_substr(number, 0, lenght);
	value = ft_atoi(number_string);
	free(number_string);
	return (value);
}

int	number_digits(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}
