/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:19:26 by guilmira          #+#    #+#             */
/*   Updated: 2021/05/30 16:12:23 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_digits(int n)
{
	int	digits;

	digits = 0;
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static void	itoa_writer(int n, char *ptr)
{
	static int			i;

	if (n / 10 != 0)
		itoa_writer(n / 10, ptr);
	else
	{
		i = 0;
		if (n < 0)
		{
			ptr[i++] = '-';
		}
	}
	if (n < 0)
		n *= -1;
	ptr[i] = '0' + n % 10;
	ptr[++i] = '\0';
}

char	*ft_itoa(int n)
{
	char	*ptr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ptr = ft_calloc(number_digits(n) + 2, sizeof(char));
	if (!ptr)
		return (NULL);
	itoa_writer(n, ptr);
	return (ptr);
}
