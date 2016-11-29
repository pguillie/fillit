/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:36:05 by pguillie          #+#    #+#             */
/*   Updated: 2016/11/29 16:29:19 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

char	**ft_check(int fd);
int		ft_checkbeside(char *tetri);
int		ft_solve(char **tetri, char *sol, int size);
void	ft_errors(char *s, int fd);
int		ft_space(char *sol, char *tetri, int size, int pos);
void	ft_append(char *map, char *t, int pos);
void	ft_erase(char *map, char *t);
void	ft_disp(char *map, int n);
char	*ft_init(int len);
int		ft_sizemin(char **t);

#endif
