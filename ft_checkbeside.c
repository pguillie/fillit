/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbeside.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:54:04 by pguillie          #+#    #+#             */
/*   Updated: 2016/11/29 16:38:15 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_beside(char *s, int i)
{
	int		blocks;

	blocks = 0;
	if (i > 3)
	{
		if (s[i - 4] != '.')
			blocks++;
	}
	if (i % 4 > 0)
	{
		if (s[i - 1] != '.')
			blocks++;
	}
	if (i % 4 < 3)
	{
		if (s[i + 1] != '.')
			blocks++;
	}
	if (i < 12)
	{
		if (s[i + 4] != '.')
			blocks++;
	}
	return (blocks);
}

int			ft_checkbeside(char *t)
{
	int		i;
	int		b;
	int		couple;

	i = 0;
	couple = 0;
	while (t[i])
	{
		if (t[i] != '.')
		{
			b = ft_beside(t, i);
			if (!b)
				return (0);
			else if (b >= 2)
				couple++;
		}
		i++;
	}
	return (couple > 0 ? 1 : 0);
}
