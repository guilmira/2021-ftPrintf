/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:29:19 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/23 08:42:03 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define CONVERTERS "%idcspuxX"
# define HEXADECIMAL "0123456789abcdef"
# define HEXADECIMAL_MAYUS "0123456789ABCDEF"
# define PREFIX "0x"
# define PREFIX_MAYUS "0X"

typedef struct s_flags
{
	char	signal;
	int		zerofilled;
	int		zerofilled_total_digits;
	int		alignment;
	char	alignment_sign;
	int		alignment_total_spaces;
	int		precision;
	int		precision_total_digits;
	int		invisible_sign;
	int		plus_sign;
	int		alternative;
	int		counter;
}			t_flag;

int		ft_printf(const char *c, ...);
/** Fd management */
void	pf_putstr_fd(char *s, int fd, t_flag *flag);
void	pf_putchar_fd(char c, int fd, t_flag *flag);
void	pf_pointer_fd(unsigned long long n, char *base, int fd, t_flag *flag);
/** Manipulate_numbers */
int		get_number_from_string(char *number);
int		ft_count_digits_unsigned(unsigned int n);
/** Tools */
void	init_flag(t_flag *flag);
void	left_align_int(int sign, int lenght, int number_zeros, t_flag *flag);
void	print_end(int number_zeros, int lenght, char *str, t_flag *flag);
int		check_flag_zerofilled(t_flag *flag, int lenght);
/** Printf format */
void	get_flags(char *str, t_flag *flag, va_list x);
void	get_allignment(char *str, t_flag *flag, va_list x);
void	get_precision(char *str, t_flag *flag, va_list x);
char	*get_flag_string(char *str);
/** Printf prints */
void	print_char(int c, t_flag *flag);
void	print_string(char *str, t_flag *flag);
void	print_pointer(unsigned long long n, t_flag *flag);
void	print_integer(int integer, t_flag *flag);
void	print_integer_unsigned(unsigned int unsig, t_flag *flag);
void	print_hexa(unsigned int hexa, t_flag *flag, char *base, char *prefix);

#endif
