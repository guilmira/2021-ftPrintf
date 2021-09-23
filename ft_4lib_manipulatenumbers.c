/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_4lib_manipulatenumbers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:32:40 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/23 07:46:43 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** PURPOSE : Selects number part in any strings, trims it and applies atoi */
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

/** PURPOSE : counts digits of an unsigned int (iterative) */
int	ft_count_digits_unsigned(unsigned int n)
{
	int	digits;

	digits = 1;
	n /= 10;
	while (n)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}
