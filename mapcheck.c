/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:41:18 by abeaudui          #+#    #+#             */
/*   Updated: 2023/01/19 18:48:46 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"


int checkextension(char *s) // check extension
{
	int i;
	while(s[i] != '.')
		i++;
	i = i + 1;
	if ((s[i] == 'b') && (s[i+1] == 'e') && (s[i+2] == 'r'))
		return(1);
	else
		{
			printf("%s n'est pas un type de fichier adequat", s);
			return (0);
		}
	
}

int countfirstline(char *s) // si premiere ligne vaut au moins 4
{

	int fd;
	int stock;

	stock = 0;
	fd = open(s,O_RDWR);
	stock = strlen(get_next_line(fd));
	close(fd);
	stock = stock -1; 
	return(stock);
}

int counttotal(char *s)
{
	int fd;
	int i;
	int colonne;
	char *str;
	
	colonne = 0;
	i = 1;
	fd = open(s, O_RDWR);
	str = get_next_line(fd);
	while (str)
	{
		i = i + strlen(str);
		str = get_next_line(fd);
		colonne++;
	}
	i = i - colonne;
	close(fd);
	return(i);
}



int isitarectangle(char *s) // A CHECK
{
	int fd;
	int check;
	int check1;
	char *str;
	int i;
	
	check = 0;
	check1 = 0;
	fd = open(s, O_RDWR);
	str = get_next_line(fd);


	while (!(str == NULL))
	{	

		
		if ((str[strlen(str) - 1] == '\n'))
			check = strlen(str) - 1;
		else
			check = strlen(str);
		str = get_next_line(fd);
		if ((str[strlen(str) - 1] == '\n'))
			check1 = strlen(str) - 1;
		else
			check1 = strlen(str);
		if(check1 != check)
			return (0);
		if(str[check1] == '\0')
			break;
		
	}
	
	close(fd);
	return (1);
	
}


int		checkall(char *s)
{
	if (checkextension(s) == 1 && countfirstline(s) >= 4 && counttotal(s) >= 16 &&  isitarectangle(s) == 1 && check_C(s) == 1 && check_E(s) == 1 && check_P(s) == 1 && check_other(s) == 1 )	
		return(1);
	else
		return (0);
}