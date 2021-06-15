/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:29:19 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/15 16:21:06 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

# include <stdio.h>

typedef struct s_flags
{
	char	signal;
	int		alignment_sign;
	int		total_alignment_spaces;
	int		invisible_plus_sign; // el espacio
	int		plus_sign;	// +
	int		zerofilled;

}			t_flag;

int			ft_printf(const char *c, ...);
int			check_ifis_converter(char c);
void		init_flag(t_flag *flag);
int			allignment(char *number);
int			number_digits(int n);

#endif
