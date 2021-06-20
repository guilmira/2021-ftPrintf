/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 11:33:29 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/20 12:15:23 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flags(char *str, t_flag *flag)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '.')
			break;
		if (str[i] == '0' && !(ft_isdigit(str[i + 1])))
			flag->zerofilled = get_number_from_string(&(str)[i + 1]);
		if (str[i] == '+')
			;
		if (str[i] == '#')
			;
	}
}

void	get_allignment(char *str, t_flag *flag, va_list x)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '.')
			break;
		if (str[i] == '-')
			flag->alignment_sign = '-';
		if (ft_isdigit(str[i]) && !(flag->zerofilled_total_digits))
		{
			flag->alignment = 1;
			flag->alignment_total_spaces = get_number_from_string(&(str)[i]);
		}
		if (str[i] == '*' && !(flag->alignment))
		{
			flag->alignment = 1;
			flag->alignment_total_spaces = va_arg(x, int);
		}
		if (flag->alignment_total_spaces < 0)
		{
			flag->alignment_total_spaces *= -1;
			flag->alignment_sign = '-';
		}
	}
}

void	get_precision(char *str, t_flag *flag, va_list x)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) && !(flag->precision))
		{
			flag->precision = 1;
			flag->precision_total_digits = get_number_from_string(&(str)[i]);
		}
		if (str[i] == '*' && !(flag->precision))
			flag->precision_total_digits = va_arg(x, int);
	}
	if (flag->precision_total_digits < 0)
		flag->precision = 0;
}

void advance_string(char **str, char *new_position)
{
	if (new_position)
		*str = new_position;
}

char	*get_flag_string(char *str)
{
	if (ft_strchr_plus(str, CONVERTERS))
		return (ft_substr(str, 0, ft_strchr_plus(str, CONVERTERS) - str));
	else
		return (NULL);
}
