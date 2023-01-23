/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:49:07 by abeaudui          #+#    #+#             */
/*   Updated: 2023/01/23 12:55:47 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int map_size(char *s) 
{
	char	*str;
	int		i;
	int		fd;

	i = 0;
	fd = open(s, O_RDWR);
	if(fd == -1)
		return (0); 
	str = get_next_line(fd);
	while (str)
	{
		i++;
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (i);
}

char **create_map(char *s)
{
	char	**map;
	char	*str;
	int		i;
	int		fd;
	int		size;

	i = 0;
	fd = open(s, O_RDWR);
	if (fd == -1)
		return (NULL);
	size = map_size(s);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	str = get_next_line(fd);
	while (str)
	{
		map[i] = str;
		str = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	free(str);
	close(fd);
	return (map);
}