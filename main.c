/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:16:41 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/20 12:16:35 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{

	//i = 0x12; //con 0 delante es formato octal
	int j;
	int z = 0;


	z = printf(" *%-*.*d* *%*.*d* gg\n", 4, 5, 10, 10, 21, -10);
	j = ft_printf(" *%-*.*d* *%*.*d* gg\n", 4, 5, 10, 10, 21, -10);

	//z = printf("%-*.*d* \n", 4, 5, 10);
	//j = ft_printf("%-*.*d* \n", 4, 5, 10);

	//z = printf("\\ %d s\n", 0);
	//j = ft_printf("\\ %d s\n", 0);
	printf("%i\n", z);
	printf("%i\n", j);

	return (0);
}
