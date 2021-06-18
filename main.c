/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:16:41 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/18 15:31:21 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{

	//i = 0x12; //con 0 delante es formato octal

	//char *s = "hello";
	//const char *str = "%0-9i y %0-9.2i  bah\n";
	//const char *str = "%-*.*d y %.*d\n";
	const char *str = "%-*.*d y %.*d\n";
	//const char *str = "%x   go\n";
	ft_printf(str, 8, 6, 4, 3, 2);
	printf(str, 8, 6, 4, 3, 2);
	//printf(str, i);
	//printf("%s", str);
	return (0);
}
