/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:16:41 by guilmira          #+#    #+#             */
/*   Updated: 2021/07/01 14:21:12 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

 int	main(void)
{

	 //i = 0x12; //con 0 delante es formato octal
	int j = 0;
	int z = 0;
	int xx = -10;
	int *ptr1 = &xx;


	printf("%20p\n", -15);
	ft_printf("%20p\n", -15);
	ft_printf("\n");
	ft_printf("%i\n", z);
	ft_printf("%i\n", j);


	//system("leaks a.out");
	return (0);
}

