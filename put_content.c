/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:09:14 by arnaud            #+#    #+#             */
/*   Updated: 2023/01/29 15:33:40 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void mlx_put(t_data *data, void *path, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, path, GAMESIZE * x, GAMESIZE * y);
}

void put_walls(t_data *data, int x, int y, char **map)
{
	int	i;
	int	j;
	int k;

	k = 0;
	i = 0;
	j = 0;
	while ( i < y )
	{
		j = 0;
		while ( j < x) 
		{
			if(map[i][j] == '1') 
					mlx_put(data, data->wall, j, i);
			j++;
		}
		i++;
	}
}

void put_floor(t_data *data, int x, int y, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if(map[i][j] == '0')
				mlx_put(data, data->floor, j, i);
			j++;
		}
		i++;
	}
}

void put_character(t_data *data, int x, int y, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if(map[i][j] == 'P')
				mlx_put(data, data->chara, j, i);
			j++;
		}
		i++;
	}
}

void put_exit(t_data *data, int x, int y, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < y )
	{
		j = 0;
		while (j < x)
		{
			if(map[i][j] == 'E')
				mlx_put(data, data->exit, j, i);
			j++;
		}
		i++;
	}
}

void put_collectible(t_data *data, int x, int y, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < y)
	{
		j = 0;
		while (j < x )
		{
			if(map[i][j] == 'C')
				mlx_put(data, data->collectible, j, i);
			j++;
		}
		i++;
	}
}