
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


# define WINDOW_HEIGHT 900
# define WINDOW_WIDTH 900
# define MLX_ERROR 1


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int 	countfirstline(char *s);
int 	checkextension(char *s);
int 	counttotal(char *s);
int 	isitarectangle(char *s);
int		init(void);

int		ft_strlen(char *str);
char	*read_and_addtostash(char *stash, int fd);
char	*extract_and_addtoline(char *stash);
char	*get_next_line(int fd);
char	*collect_andaddtostash(char *stash);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		 check_C(char *s);
int 	 check_P(char *s);
int 	 check_E(char *s);
int  	check_other(char *s);
int		checkall(char *s);




typedef struct s_data

{
	void	*mlx_ptr;
	void 	*mlx_win;

	int		img_width;
	int 	img_height;
	char 	img_path;


}		t_data;

#endif