/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:16:41 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/20 14:50:53 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


 int	main(void)
{

	 //i = 0x12; //con 0 delante es formato octal
	int j = 0;
	int z = 0;
//\n
	z = printf("%4s %6sjue", "123", "45\n");
	j = ft_printf("%4s %6sjue", "123", "45\n");
	printf("%i\n", z);
	printf("%i\n", j);

	//system("leaks a.out");
	return (0);
}
