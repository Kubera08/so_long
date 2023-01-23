/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheckcollectibles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:11:09 by abeaudui          #+#    #+#             */
/*   Updated: 2023/01/23 14:12:25 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int check_only_C_E_P_1_0(char **map)
{
	int i;
	int j;
	char *str;

	i = 0;

	while (map[i])
	{
		str = map[i];
		j = 0;
		while (str[j])
		{
			if(str[j] != 'C' && str[j] != 'P' && str[j] != 'E' && str[j] != '1' &&  str[j] != '0' &&  str[j] != '\n' &&  str[j] != '\0' )
			{
				return (1);
			}	

			j++;
 		}
		i++;		
	}
	return(0);
}