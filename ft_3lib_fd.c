/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3lib_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 10:02:57 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/30 13:00:10 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd, t_flag *flag)
{
	if (s)
		flag->counter += write(fd, s, ft_strlen(s));

}

void	ft_putchar_fd(char c, int fd, t_flag *flag)
{
	flag->counter += write(fd, &c, sizeof(char));
}

void	ft_positivepointer_fd(unsigned long long n, char *base, int fd, t_flag *flag)
{
	int					i;
	unsigned long long	x;

	i = -1;
	if (!base || !base[0])
		return ;
	while (base[++i])
		if (ft_strchr(base + 1 + i, base[i]) || \
		ft_strchr(base, '+') || ft_strchr(base, '-'))
			return ;
	x = n;
	if (x / ft_strlen(base) == 0)
		ft_putchar_fd(base[x % ft_strlen(base)], fd, flag);
	else
	{
		ft_positivepointer_fd(x / ft_strlen(base), base, fd, flag);
		ft_putchar_fd(base[x % ft_strlen(base)], fd, flag);
	}
}
