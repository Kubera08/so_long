/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:59:16 by abeaudui          #+#    #+#             */
/*   Updated: 2023/02/09 16:08:18 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = read_and_addtostash(stash, fd);
	if (!stash)
		return (NULL);
	line = extract_and_addtoline(stash);
	stash = collect_andaddtostash(stash);
	return (line);
}

char	*read_and_addtostash(char *stash, int fd)
{
	int		check;
	char	*buffer;

	check = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[check] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (check == 0 && stash)
		{
			free (buffer);
			return (stash);
		}
	}
	free (buffer);
	return (stash);
}

char	*extract_and_addtoline(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!*stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*collect_andaddtostash(char *stash)
{
	char	*rest;
	int		i;
	int		j;

	j = 0;
	i = 0;
	rest = NULL;
	while (stash[i] && stash[i] != '\n')
			i++;
	if (!stash[i])
	{
		free (stash);
		return (NULL);
	}		
	rest = malloc(sizeof(char) * (ft_strlen(stash) - i) + 1);
	if (!rest)
		return (NULL);
	i = i + 1;
	while (stash[i])
		rest[j++] = stash[i++];
	rest[j] = '\0';
	free (stash);
	return (rest);
}
