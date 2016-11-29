/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:21:43 by pbourlet          #+#    #+#             */
/*   Updated: 2016/11/29 16:36:44 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_count(char *map, int n)
{
	int		i;
	int		blocks;

	i = 0;
	blocks = 0;
	while (i < (n - 1) * 42 + n)
	{
		if (!((i - n) % 42) && i >= n)
			i = i - n + 42;
		if (map[i] != '.')
			blocks++;
		i++;
	}
	return (blocks);
}

int			ft_space(char *map, char *tetri, int n, int i)
{
	char	*dup;
	int		before;

	if (!(dup = ft_strdup(map)))
		return (-1);
	before = ft_count(map, n);
	while (i < (n - 1) * 42 + n)
	{
		if (!((i - n) % 42) && i >= n)
			i = i - n + 42;
		if (map[i] == '.')
		{
			ft_append(dup, tetri, i);
			if (ft_count(dup, n) - before == 4)
			{
				free(dup);
				return (i);
			}
			ft_strcpy(dup, map);
		}
		i++;
	}
	free(dup);
	return (-1);
}
