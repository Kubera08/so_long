/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:00:29 by abeaudui          #+#    #+#             */
/*   Updated: 2023/02/26 13:29:46 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int ac, char **av)
{
	t_data	data;

	data.title = av[1];
	if (ac == 2)
	{
		if (checkextension(data.title) == 0)
		{		
			data.map = create_map(data.title);
			if (check_all(data) == 0)
				init(&data);
			else
			{
				printf ("Error: la map ne remplit pas les conditions requises\n");
				return (0);
			}
		}
	}
}
