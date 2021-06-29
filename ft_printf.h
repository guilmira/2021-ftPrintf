/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:29:19 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/29 12:32:18 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define CONVERTERS "idcspuxX%"
# define HEXADECIMAL "0123456789abcdef"

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

	int		invisible_plus_sign; // el espacio
	int		plus_sign;	// +

	int		counter;


}			t_flag;

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
void	ft_positivepointer_fd(unsigned long long n, char *base, int fd, t_flag *flag);

void	ft_putnbr_fd(int n, int fd, t_flag *flag);
/** Manipulate_numbers */
int		get_number_from_string(char *number);
int		ft_count_digits(int n);
char	*ft_itoa(int n);
/** Utils */
void		init_flag(t_flag *flag);

int			check_ifis_converter(char c);

/** Printf format */
char	*get_flag_string(char *str);
void	get_flags(char *str, t_flag *flag, va_list x);
void	get_allignment(char *str, t_flag *flag, va_list x);
void	get_precision(char *str, t_flag *flag, va_list x);
void	advance_string(char **str, char *new_position);
/** Printf prints */
void	print_char(int c, t_flag *flag);
void	print_string(char *str, t_flag *flag);
void	print_integer(int integer, t_flag *flag);
void	print_hexa(unsigned long long n, t_flag *flag);


int		ft_printf(const char *c, ...);

#endif
