/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:10:34 by guilmira          #+#    #+#             */
/*   Updated: 2021/05/30 12:41:40 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char const c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	if (s1 && set)
	{
		j = ft_strlen(s1);
		i = -1;
		while (s1[++i])
			if (check_set(s1[i], set) == 0)
				break ;
		while (--j > 0)
			if (check_set(s1[j], set) == 0)
				break ;
		if (j == 0)
			return (ft_substr(s1, i, j));
		return (ft_substr(s1, i, j + 1 - i));
	}
	return (0);
}
