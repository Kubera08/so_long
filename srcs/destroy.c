/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:40:33 by abeaudui          #+#    #+#             */
/*   Updated: 2023/02/09 15:09:41 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_maps(char **map, t_data *data)
{
	int		i;

	i = 0;
	while (i < data->y_size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_maps2(char **map, t_data data)
{
	int		y;
	int		i;

	i = 0;
	y = map_size(data.title);
	while (i < y)
	{
		free(map[i]);
		i++;
	}
	free (map);
}

int	destroy(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_image(data->mlx_ptr, data->floor);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_image(data->mlx_ptr, data->chara);
	mlx_destroy_image(data->mlx_ptr, data->collectible);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	mlx_loop_end(data->mlx_ptr);
	free(data->mlx_ptr);
	free_maps(data->map, data);
	exit(1);
}
