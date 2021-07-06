/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:16:41 by guilmira          #+#    #+#             */
/*   Updated: 2021/07/05 16:00:03 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int t = printf(s, 1);
	int j = ft_printf(s, 1);
	ft_printf("%i\n", t);
	ft_printf("%i\n", j);
	return (0);
}
//system("leaks a.out");
