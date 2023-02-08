/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:32:09 by abeaudui          #+#    #+#             */
/*   Updated: 2023/02/08 14:24:25 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void *init_content (t_data *data)
{
	
	data->x_size = (ft_strlen(data->map[1]) - 1);
	data->y_size = map_size(data->title);


	data->x_pos = get_pos_x(data->map, 'P') ;
	data->y_pos = get_pos_y(data->map, 'P') ;

	
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (NULL);
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->x_size * GAMESIZE,
			data->y_size * GAMESIZE, "so_long");
	if (data->mlx_win == NULL)
		return (NULL);

	data->wall = ft_put_img(data, "xpm/sapin1.xpm");
	data->wall2 = ft_put_img(data, "xpm/sapin2.xpm");
	data->wall3 = ft_put_img(data, "xpm/sapin3.xpm");
  
	data->floor = ft_put_img(data, "xpm/snow.xpm");
	data->chara = ft_put_img(data, "xpm/chara.xpm");
	data->exit = ft_put_img(data, "xpm/exit.xpm");
	data->collectible = ft_put_img(data, "xpm/cadeau.xpm");

	return (data);
}

int	handle_no_event(void *data)
{
	char *i;
	i = data;
	i++;

	return (0);
}

int handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape) 
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
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

int	handle_keyrelease()
{
	static int i;
	i = i + 1;
	printf("Nombre de mouvements: %d\n", i);
	return(i);
}

/*
int handle_mousepress(int keycode, t_data *data)
{
	if(keycode == 1 && )
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	return(0);
}

*/


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
  
// initialisation et création de fenêtre
	

	
// Register events before the loop starts = hooks functions

	// key events
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, &handle_keyrelease, data);
	//mlx_mouse_hook(data->mlx_win, &handle_mousepress, data);
			
// render 
	put_walls(data, data->x_size, data->y_size, data->map);
	put_floor(data, data->x_size, data->y_size, data->map);
	put_character(data, data->x_size, data->y_size, data->map);
	put_exit(data, data->x_size, data->y_size, data->map);
	put_collectible(data, data->x_size, data->y_size, data->map);

// loop

	mlx_loop(data->mlx_ptr);
	mlx_loop_end(data->mlx_ptr);


// clear
	destroy(data);
	
} 


void	destroy(t_data *data)
{
	free_maps(data->map, data);
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_image(data->mlx_ptr, data->floor);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_image(data->mlx_ptr, data->chara);
	mlx_destroy_image(data->mlx_ptr, data->collectible);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

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
	free(map);
}