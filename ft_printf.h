/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:29:19 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/18 10:38:09 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft_submodulo/libft.h"

# include <stdio.h>

typedef struct s_flags
{
	char	signal;
	char	alignment_sign;
	int		total_alignment_spaces;
	int		precision_digits;
	int		invisible_plus_sign; // el espacio
	int		plus_sign;	// +
	int		zerofilled;

}			t_flag;

int			ft_printf(const char *c, ...);
int			check_ifis_converter(char c);
void		init_flag(t_flag *flag);
int			get_number_from_string(char *number);
int			number_digits(int n);

//prints
void	print_integer(int integer, t_flag flag);

#endif
