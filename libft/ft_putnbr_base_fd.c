/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:19:51 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/13 17:20:10 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static int	number_digits(int n)
{
	int	digits;

	digits = 0;
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
} */

void	ft_putnbr_base_fd(int n, char *base, int fd)
{
	int				i;
	unsigned int	x;

	i = -1;
	if (!base || !base[0])
		return ;
	while (base[++i])
	{
		if (ft_strchr(base + 1 + i, base[i]) || ft_strchr(base, '+') || ft_strchr(base, '-'))
			return ;
	}
	if (n < 0)
	{
		x = n * -1;
		ft_putchar_fd('-', fd);
	}
	else
		x = n;
	if (x / ft_strlen(base) == 0)
		ft_putchar_fd(base[x % ft_strlen(base)], fd);
	else
	{
		ft_putnbr_base_fd(x / ft_strlen(base), base, fd);
		ft_putchar_fd(base[x % ft_strlen(base)], fd);
	}
}
