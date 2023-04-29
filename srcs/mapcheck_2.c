/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:11:09 by abeaudui          #+#    #+#             */
/*   Updated: 2023/02/09 15:36:26 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	checkcharac(char **map)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (map[i])
	{
		str = map[i];
		j = 0;
		while (str[j++])
		{
			if (str[j] != 'C' && str[j] != 'P' && str[j] != 'E'
				&& str[j] != '1' && str[j] != '0'
				&& str[j] != '\n' && str[j] != '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_pe(char **map)
{
	int		i;
	int		j;
	int		e;
	int		p;
	char	*str;

	i = 0;
	p = 0;
	e = 0;
	while (map[++i])
	{	
		str = map[i];
		j = 0;
		while (str[j++])
		{
			if (str[j] == 'P')
				p++;
			if (str[j] == 'E')
				e++;
			if (p >= 2 || e >= 2)
				return (1);
		}
	}
	return (0);
}

int	check_collect(char **map)
{
	int		i;
	int		j;
	int		collectibles;
	char	*str;

	i = 0;
	collectibles = 0;
	while (map[++i])
	{
		str = map[i];
		j = 0;
		while (str[j++])
			if (str[j] == 'C')
			collectibles++;
	}
	return (collectibles);
}
