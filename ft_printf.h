/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:29:19 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/20 10:12:45 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define CONVERTERS "idcspuxX%"
//# include "./libft_submodulo/libft.h"

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

int			ft_printf(const char *c, ...);
int			check_ifis_converter(char c);
void		init_flag(t_flag *flag);
int			get_number_from_string(char *number);
int			number_digits(int n);

//prints
void	print_integer(int integer, t_flag *flag);


//libft
void	ft_putstr_fd(char *s, int fd, t_flag *flag);
void	ft_putchar_fd(char c, int fd, t_flag *flag);
void	ft_punteropositivo_fd(unsigned long long n, char *base, int fd, t_flag *flag);
void	ft_putnbr_fd(int n, int fd, t_flag *flag);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

//libdt2
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strchr_plus(char *str, char *letters);
#endif
