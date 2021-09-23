/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3lib_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 10:02:57 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/23 08:39:36 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putstr_fd(char *s, int fd, t_flag *flag)
{
	if (s)
		flag->counter += write(fd, s, ft_strlen(s));
}

void	pf_putchar_fd(char c, int fd, t_flag *flag)
{
	flag->counter += write(fd, &c, sizeof(char));
}

void	pf_pointer_fd(unsigned long long n, char *base, int fd, t_flag *flag)
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
		pf_putchar_fd(base[x % ft_strlen(base)], fd, flag);
	else
	{
		pf_pointer_fd(x / ft_strlen(base), base, fd, flag);
		pf_putchar_fd(base[x % ft_strlen(base)], fd, flag);
	}
}

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
