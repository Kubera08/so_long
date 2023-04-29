/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:32:09 by abeaudui          #+#    #+#             */
/*   Updated: 2023/02/09 15:08:43 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	*init_content(t_data *data)
{
	data->x_size = (ft_strlen(data->map[1]) - 1);
	data->y_size = map_size(data->title);
	data->x_pos = get_pos_x(data->map, 'P');
	data->y_pos = get_pos_y(data->map, 'P');
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (NULL);
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->x_size * GAMESIZE,
			data->y_size * GAMESIZE, "so_long");
	if (data->mlx_win == NULL)
		return (NULL);
	data->wall = ft_put_img(data, "xpm/sapin1.xpm");
	data->floor = ft_put_img(data, "xpm/snow.xpm");
	data->chara = ft_put_img(data, "xpm/chara.xpm");
	data->exit = ft_put_img(data, "xpm/exit.xpm");
	data->collectible = ft_put_img(data, "xpm/cadeau.xpm");
	return (data);
}

int	handle_no_event(void *data)
{
	char	*i;

	i = data;
	i++;
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape || keysym == 113)
		destroy(data);
	if (keysym == XK_w)
		move_up(data);
	if (keysym == XK_s)
		move_down(data);
	if (keysym == XK_a)
		move_left(data);
	if (keysym == XK_d)
		move_right(data);
	return (0);
}

void	init(t_data *data)
{	
	data = init_content(data);
	if (data == NULL)
	{
		return ;
	}
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->x_size, data->y_size);
	if (!data->img_ptr)
		return ;
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->mlx_win, 17, 0, &destroy, data);
	put_walls(data, data->x_size, data->y_size, data->map);
	put_floor(data, data->x_size, data->y_size, data->map);
	put_character(data, data->x_size, data->y_size, data->map);
	put_exit(data, data->x_size, data->y_size, data->map);
	put_collectible(data, data->x_size, data->y_size, data->map);
	mlx_loop(data->mlx_ptr);
	destroy(data);
}
