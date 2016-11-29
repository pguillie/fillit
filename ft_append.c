/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:31:55 by pguillie          #+#    #+#             */
/*   Updated: 2016/11/28 17:30:10 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_append(char *map, char *tetri, int pos)
{
	int		i;
	int		j;

	i = 0;
	while (tetri[i] == '.')
		i++;
	j = i;
	while (tetri[i])
	{
		if (!(i % 4) && i != j)
			pos += 42 - 4;
		if (tetri[i] != '.')
			map[pos] = tetri[i];
		i++;
		pos++;
	}
}
