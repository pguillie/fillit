/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:12:01 by pbourlet          #+#    #+#             */
/*   Updated: 2016/11/28 17:36:33 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sizemin(char **t)
{
	int		i;
	int		offset;

	i = 0;
	offset = 0;
	while (t[i])
		i++;
	while (ft_sqrt(i * 4 + offset) == 0)
		offset++;
	return (ft_sqrt(i * 4 + offset));
}
