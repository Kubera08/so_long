/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:59:16 by abeaudui          #+#    #+#             */
/*   Updated: 2023/01/27 19:16:06 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;



	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = read_and_addtostash(stash, fd); // notre stash est remplie par le contenu du buffer et peut potentiellement comprendre un \n
	if (!stash)
		return (NULL);
	line = extract_and_addtoline(stash); // on extrait de notre stash et on remplit line jusqu'a rencontrer un \n ou un \0
	stash = collect_andaddtostash(stash);  // on va extraire de stash les potentiels characteres qui depassaient le \n et les stocker
	
	return(line); 
}
/* utiliser read pour ajouter les charactres au buffer puis from buffer to stash */
char	*read_and_addtostash(char *stash, int fd)
{
	int	check;
	char	*buffer;

	check = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);		
	while (!ft_strchr(stash, '\n'))
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1 ) // si read echoue
		{
			free(buffer);
			return (NULL);
		}
		buffer[check] = '\0'; // car check sera toujours la taille de stash
		stash = ft_strjoin(stash, buffer);
		if (check == 0 && stash) // si t'es au dernier mot 
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
	int 	i;
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
	int	i;
	int	j;
	
	j = 0;
	i = 0;
	rest = NULL;
	while (stash[i] && stash[i] != '\n')
			i++;
	if (!stash[i]) // si il n'y a pas de characteres apres le \n
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
