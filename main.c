/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:16:41 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/18 11:58:39 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int i;
	//i = 0x12; //con 0 delante es formato octal
	i = 0x20A;
	//char *s = "hello";
	//const char *str = "%0-9i y %0-9.2i  bah\n";
	//const char *str = "%06i y %0-9.2i  bah\n";
	const char *str = "%x   go\n";
	ft_printf(str, i);
	//printf(str, i, i);
	printf(str, i);
	//printf("%s", str);
	return (0);
}
