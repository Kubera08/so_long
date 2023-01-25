/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:32:09 by abeaudui          #+#    #+#             */
/*   Updated: 2023/01/24 19:15:24 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

#include "solong.h"
	
void *init_content (t_data *data)
{
	


	data->x_size = ft_strlen(data->map[0]) - 1;
	data->y_size = map_size(data->title);
	
	data->x_pos = get_pos_x(data->map, 'P') + 1;
	data->y_pos = get_pos_y(data->map, 'P') + 1;
	
	data->place = (data->x_size % data->x_pos * GAMESIZE);
	data->place2 = (data->y_size % data->y_pos * GAMESIZE);

	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (NULL);
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->x_size * GAMESIZE,
			data->y_size * GAMESIZE, "so_long");
	if (data->mlx_win == NULL)
		return (NULL);
		
	data->wall = ft_put_img(data, "xpm/wall.xpm");
	data->floor = ft_put_img(data, "xpm/flocons.xpm");
	data->chara = ft_put_img(data, "xpm/ski.xpm");
	data->exit = ft_put_img(data, "xpm/panneau.xpm");

	return (data);
	
}
/*
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
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	char *i;

	i = data;
	i++;
	
	printf("Keyrelease: %d\n", keysym);
	return (0);
	
}
*/
int	init(t_data *data)
{
	
	data = init_content(data);
	if (data == NULL)
	{
		return (0);
	}
	
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->x_size, data->y_size);
	
	put_walls(data, data->x_size, data->y_size, data->map);
	put_floor(data, data->x_size, data->y_size, data->map);
	put_character(data, data->x_size, data->y_size, data->map);
	put_exit(data, data->x_size, data->y_size, data->map);

// initialisation et création de fenêtre
	

	
// Register events before the loop starts = hooks functions



	// key events

	
	//mlx_loop_hook(data->mlx_ptr, &handle_no_event, data); // exécutée quand pas d'event sinon la boucle ne s'arrête jamais
	//mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &handle_keypress, data); // fonction handle_keypress exécutée à chaque fois qu'une touche est pressée
	//mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, &handle_keyrelease, data); // fonction handle_keyrelease exécutée à chaque fois qu'une touche est relachée


// loop

	mlx_loop(data->mlx_ptr);

// clear

	//mlx_destroy_display(data->mlx_ptr);
	// mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	
	// free (data->mlx_ptr);
	return(0);

} 


