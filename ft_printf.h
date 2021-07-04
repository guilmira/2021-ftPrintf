/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:29:19 by guilmira          #+#    #+#             */
/*   Updated: 2021/07/04 14:33:50 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define CONVERTERS "idcspuxX%"
# define HEXADECIMAL "0123456789abcdef"
# define HEXADECIMAL_MAYUS "0123456789ABCDEF"

# include <stdio.h>

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
/** Memory basics */
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
/** Complex strings */
char	*ft_strchr(const char *s, int c);
char	*ft_strchr_plus(char *str, char *letters);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
/** Fd management */
void	ft_putstr_fd(char *s, int fd, t_flag *flag);
void	ft_putchar_fd(char c, int fd, t_flag *flag);
void	ft_pointer_fd(unsigned long long n, char *base, int fd, t_flag *flag);
/** Manipulate_numbers */
int		get_number_from_string(char *number);
int		ft_count_digits(int n);
int		ft_count_digits_unsigned(unsigned int n);
char	*ft_itoa(int n);
/** Utils */
void	init_flag(t_flag *flag);

void	left_align_int(int sign, int lenght, int number_zeros, t_flag *flag);
void	print_end(int number_zeros, int lenght, char *str, t_flag *flag);
int		check_flag_zerofilled(t_flag *flag, int lenght);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/** Printf format */
char	*get_flag_string(char *str);
void	get_flags(char *str, t_flag *flag, va_list x);
void	get_allignment(char *str, t_flag *flag, va_list x);
void	get_precision(char *str, t_flag *flag, va_list x);
void	advance_string(char **str, char *new_position);
/** Printf prints */
void	print_char(int c, t_flag *flag);
void	print_string(char *str, t_flag *flag);
void	print_pointer(unsigned long long n, t_flag *flag);
void	print_integer(int integer, t_flag *flag);
void	print_integer_unsigned(unsigned int unsig, t_flag *flag);
void	print_hexa(unsigned int hexa, t_flag *flag, char *base);

#endif
