/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 09:29:13 by guilmira          #+#    #+#             */
/*   Updated: 2021/05/27 17:09:49 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	x;

	if (n < 0)
	{
		x = n * -1;
		ft_putchar_fd('-', fd);
	}
	else
		x = n;
	if (x / 10 == 0)
		ft_putchar_fd('0' + x, fd);
	else
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putchar_fd('0' + (x % 10), fd);
	}
}
