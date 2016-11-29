/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:14:39 by pguillie          #+#    #+#             */
/*   Updated: 2016/11/29 16:47:09 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		file;
	char	**tetriminos;
	char	*solution;
	int		size;
	int		end;

	if (ac != 2)
		ft_errors("usage : ./fillit file", 2);
	if ((file = open(av[1], O_RDONLY)) < 0)
		ft_errors("error", 1);
	tetriminos = ft_check(file);
	close(file);
	if (!tetriminos || !(solution = ft_init(1764)))
		ft_errors("error", 1);
	end = 0;
	size = ft_sizemin(tetriminos);
	while (!end)
		end = ft_solve(tetriminos, solution, size++);
	ft_disp(solution, size - 1);
	free(tetriminos);
	free(solution);
	return (0);
}
