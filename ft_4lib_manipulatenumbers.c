/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_4lib_manipulatenumbers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:32:40 by guilmira          #+#    #+#             */
/*   Updated: 2021/07/04 13:32:33 by guilmira         ###   ########.fr       */
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

/** PURPOSE : counts digits of an int (iterative) */
int	ft_count_digits(int n)
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

/** PURPOSE : writes integer in allocated memory [recursive].
 * 1. A static int variable is defined. It will maintain its value.
 * 2. If the number is not a single digits, recurssion.
 * 3. It will eventually reach the first digit. (from 643, it will get to '6')
 * 4. Converts the first digit to a string in position i = 0;
 * 5. Converts the rest of the digits in position i = 1, i = 2...
 * 6. Always closes the string by adding a 0 at the last position of the string.
 * */
static void	itoa_writer(int n, char *ptr)
{
	static int	i;

	if (n / 10 != 0)
		itoa_writer(n / 10, ptr);
	else
	{
		i = 0;
		if (n < 0)
			ptr[i++] = '-';
	}
	if (n < 0)
		n *= -1;
	ptr[i] = '0' + n % 10;
	ptr[++i] = '\0';
}

/** PURPOSE : converts integer into its string equivalent.
 * 1. Allocates memory in heap.
 * 2. Calls recursive function itoa-writer.
 * */
char	*ft_itoa(int n)
{
	char	*ptr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ptr = ft_calloc(ft_count_digits(n) + 2, sizeof(char));
	if (!ptr)
		return (NULL);
	itoa_writer(n, ptr);
	return (ptr);
}
