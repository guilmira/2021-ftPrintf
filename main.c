/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:16:41 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/19 14:11:09 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{

	//i = 0x12; //con 0 delante es formato octal
int j;
int z = 0;
	//char *s = "hello";
	//const char *str = "%0-9i y %0-9.2i  bah\n";
	//const char *str = "%-*.*d y %.*d\n";
	/* const char *str = "%-*.*d y %.*d\n";
	//const char *str = "%x   go\n";
	j = ft_printf(str, 8, 6, 4, 3, 2);
	int z = printf(str, 8, 6, 4, 3, 2); */
	z = printf(" *%-*.*d* *%*.*d* \n", 4, 5, 10, 10, 21, -10);
	j = ft_printf(" *%-*.*d* *%*.*d* \n", 4, 5, 10, 10, 21, -10);
	printf("%i\n", z);
	printf("%i\n", j);

	return (0);
}
