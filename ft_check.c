/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:26:54 by pguillie          #+#    #+#             */
/*   Updated: 2016/11/29 22:07:27 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**ft_empty(char **t, char *buf)
{
	int		i;

	i = 0;
	while (t[i])
		free(t[i++]);
	free(buf);
	t = NULL;
	return (t);
}

static char	*ft_create(char *s)
{
	char	*t;
	int		i;
	int		nl;

	if (!(t = ft_strnew(17)))
		return (NULL);
	i = 0;
	nl = 0;
	while (i < 21)
	{
		if (s[i + nl] == '\n')
			nl++;
		t[i] = s[i + nl];
		i++;
	}
	if (nl != 4 || ft_strlen(t) != 17)
		return (NULL);
	return (t);
}

static char	*ft_convert(char *s, char l)
{
	char	*tetri;
	int		i;
	int		blocks;

	if (!(tetri = ft_create(s)))
		return (NULL);
	i = 0;
	blocks = 0;
	while (tetri[i])
	{
		if (tetri[i] != '.' && tetri[i] != '#')
			return (NULL);
		if (tetri[i] == '#')
		{
			tetri[i] = l;
			blocks++;
		}
		i++;
	}
	if (blocks != 4 || !ft_checkbeside(tetri))
		return (NULL);
	return (tetri);
}

char		**ft_check(int fd)
{
	char	**tab;
	char	*buffer;
	int		i;
	int		reading;
	char	letter;

	if (!(buffer = ft_strnew(21)))
		return (NULL);
	if (!(tab = (char**)malloc(26 * 17)))
		return (NULL);
	i = 0;
	reading = 1;
	letter = 'A';
	while (reading)
	{
		ft_strclr(buffer);
		read(fd, buffer, 20);
		tab[i++] = ft_convert(buffer, letter++);
		reading = read(fd, buffer, 1);
		if ((reading && buffer[0] != '\n') || !tab[i - 1])
			return (ft_empty(tab, buffer));
	}
	free(buffer);
	return (tab);
}
