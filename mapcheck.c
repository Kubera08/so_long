/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:41:18 by abeaudui          #+#    #+#             */
/*   Updated: 2023/01/23 19:59:42 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"


int checkextension( char *s) // check extension
{
	int i;

	i = 0;
	while(s[i] != '.')
		i++;
	i = i + 1;
	if ((s[i] == 'b') && (s[i+1] == 'e') && (s[i+2] == 'r'))
		return(0);
	else
		{
			printf("%s n'est pas un type de fichier adequat\n", s);
			return (1);
		}
}

int isitarectangle(char **map) 
{
	int i;
	int size;
	char *str;	
	int j;
	int temp;
	
	temp = strlen(map[0]);
	i = 0;
	j = 0;
	size = 0;

	while (map[j])
	{	
		
		str = map[j];
		size = 0;
		
		while(str[size])
		{
			size++;
		}
		if (temp != size && str[strlen(str) - 1] == '\n')
			return (1);
		temp = size;
		j++;
	}
	return (0);	
}

int isclosed(char **map)
{

	int i;
	char *str;	
	int j;
	
	i = 0;
	j = 0;
	
	str = map[j];
	while (str[i])
	{
		if(str[i] != '1' && str[i] != '\n' && str[i] != '\0')
			return (1);	
		i++;
	}
	i = 0;
	while (map[j])
	{	
		str = map[j];
		i = 0;
		if(str[0] != '1')
			return(1);
		else if(str[strlen(str)- 2] != '1')
			return (1);
		j++;
	}
	if(isclosed_2(map[j - 1]) == 1)
		return (1);
	return (0);	
}

int isclosed_2(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if(str[i] != '1' && str[i] != '\n' && str[i] != '\0')
			return (1);	
		i++;
	}
	return (0);
}

int check_all(char *s)
{
	t_data data;
	data.map = create_map(s);
	
	if (isitarectangle(data.map) == 0  && check_only_C_E_P_1_0(data.map) == 0 && isclosed(data.map) == 0)
		return(0);
	else
		return(1);
}