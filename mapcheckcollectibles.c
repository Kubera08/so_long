/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheckcollectibles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:11:09 by abeaudui          #+#    #+#             */
/*   Updated: 2023/01/19 18:47:12 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"


int check_C(char *s)
{

	int fd;
	int check;
	const char *str;
	fd = open(s, O_RDWR);

	while(!(str == NULL))
	{
		str = get_next_line(fd);
		if(strrchr(str, 'C') != NULL)
			return(1);
		check = strlen(str);
		
		if(str[check - 1] != '\n' )
			break;
	}
	close (fd);
	return (0);
}

int check_P(char *s)
{

	int fd;
	int check;
	const char *str;
	fd = open(s, O_RDWR);

	while(!(str == NULL))
	{
		str = get_next_line(fd);
		if(strrchr(str, 'P') != NULL)
			return(1);
		check = strlen(str);
		
		if(str[check - 1] != '\n' )
			break;
	}
	close (fd);
	return (0);
}

int check_E(char *s)
{

	int fd;
	int check;
	const char *str;
	fd = open(s, O_RDWR);

	while(!(str == NULL))
	{
		str = get_next_line(fd);
		if(strrchr(str, 'E') != NULL)
			return(1);
		check = strlen(str);
		
		if(str[check - 1] != '\n' )
			break;
	}
	close (fd);
	return (0);
}


int check_other(char *s)
{

	int fd;
	int i;
	int check;
	const char *str;
	fd = open(s, O_RDWR);

	while(!(str == NULL))
	{
		str = get_next_line(fd);
		while (str[i])
		{
			if(!((str[i] == '1') && str[i] == '0' && str[i] == 'C' && str[i] == 'E' && str[i] == 'P') )
				break;
		}
		
		check = strlen(str);
		if(str[check - 1] != '\n' )
			break;
		
	}
	close (fd);
	return (1);
	

}
