/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:16:41 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/29 13:53:51 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

 int	main(void)
{

	 //i = 0x12; //con 0 delante es formato octal
	int j = 0;
	int z = 0;
//\n
	//z = printf   ("%0*.0i*0 0*%0*.10i\n", -21, INT_MAX, 21, INT_MIN);
	int *ptr;
	int x;
	x = 5;
	ptr = &x;

	z =    printf(" 0*%d\n", 1011);
	j = ft_printf(" 0*%d\n", 1011);

	//z = printf("%097i\n", 21);
	printf("%i\n", z);
	printf("%i\n", j);

	//system("leaks a.out");
	return (0);
}
