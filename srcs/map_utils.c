/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:05:25 by arnaud            #+#    #+#             */
/*   Updated: 2023/04/25 15:16:59 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	map_size(char *s)
{
	char	*str;
	int		i;
	int		fd;

	i = 0;
	fd = open(s, O_RDWR);
	if (fd == -1)
		return (0);
	while ((str = get_next_line(fd)))
	{
		i++;
		if (str)
			free (str);
	}
	if (str)
		free (str);
	close (fd);
	return (i);
}

char	**create_map(char *s)
{
	char	**map;
	char	*str;
	int		i;
	int		fd;

	i = 0;
	fd = open(s, O_RDWR);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(char *) * (map_size(s) + 1));
	if (!map)
		return (NULL);
	str = get_next_line(fd);
	while (str)
	{
		map[i++] = ft_strdup(str);
		free(str);
		str = get_next_line(fd);
	}
	map[i] = NULL;
	if (str)
		free(str);
	close(fd);
	return (map);
}

void	*ft_put_img(t_data *data, char *path)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	return (mlx_xpm_file_to_image(data->mlx_ptr, path, &a, &b));
}

char	*ft_strdup(char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(unsigned char) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	mlx_put(t_data *data, void *path, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		path, GAMESIZE * x, GAMESIZE * y);
}
