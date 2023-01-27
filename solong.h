
#ifndef SOLONG_H
#define SOLONG_H
#include <stdlib.h>
#include <stdio.h>
#include "minilibx-linux/mlx.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>


#define GAMESIZE 100

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_data

{
	void	*mlx_ptr;
	void 	*mlx_win;
	void 	*img_ptr;

	void 	*floor;
	void 	*wall;
	void	*exit;
	void 	*chara;
	void	*collectible;

	int		img_width;
	int 	img_height;
	char 	img_path;

	char 	**map;
	char 	*title;
	int 	x_size;
	int 	y_size;

	int 	x_pos;
	int 	y_pos;

	int		place;
	int 	place2;
}		t_data;

int    check_P_E(char **map);
int		init(t_data *data);
int		ft_strlen( char *str);
char	*read_and_addtostash(char *stash, int fd);
char	*extract_and_addtoline(char *stash);
char	*get_next_line(int fd);
char	*collect_andaddtostash(char *stash);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

char 	**create_map(char *s);
int 	map_size(char *s); 
int 	check_only_C_E_P_1_0(char **map);
int 	checkextension(char *s);
int 	isitarectangle(char **map);
int 	map_size(char *s);
int 	check_all(char *s);
int 	isclosed(char **map);
int 	isclosed_2(char *s);
int 	get_pos_x(char **map, char c);
int 	get_pos_y(char **map, char c);
void	 mlx_put_content(t_data *data, int x, int y, char **map);
void 	mlx_put(t_data *data, void *path, int x, int y);
int    check_P_E(char **map);
void	*ft_put_img(t_data *data, char *path);
void  move_up(t_data *data);
void  move_down(t_data *data);
void  move_left(t_data *data);
void  move_right(t_data *data);
void destroy(t_data *data);
int    check_collect(char **map);

void put_walls(t_data *data, int x, int y, char **map);
void put_floor(t_data *data, int x, int y, char **map);
void put_character(t_data *data, int x, int y, char **map);
void put_exit(t_data *data, int x, int y, char **map);
void put_collectible(t_data *data, int x, int y, char **map);



#endif