/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 11:53:55 by pguillie          #+#    #+#             */
/*   Updated: 2016/11/28 17:37:14 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_solve(char **tetri, char *sol, int size)
{
	int		pos;

	if (!*tetri)
		return (1);
	pos = 0;
	while ((pos = ft_space(sol, *tetri, size, pos)) != -1)
	{
		ft_append(sol, *tetri, pos);
		if (ft_solve(tetri + 1, sol, size))
			return (1);
		ft_erase(sol, *tetri);
		pos++;
	}
	ft_erase(sol, *tetri);
	return (0);
}
