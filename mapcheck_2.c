/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:11:09 by abeaudui          #+#    #+#             */
/*   Updated: 2023/01/24 16:16:04 by arnaud           ###   ########.fr       */
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
int    check_P_E(char **map)
{
    int i;
    int j;
    int    e;
    int    p;
    char *str;

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
    return(0);
}