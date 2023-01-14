// 1. gérer erreurs et leaks
// verifier le nombre d'arg
// malloc notre structure
// vérifier les extensions fichier (maps)
// ouvrir les fichiers maps (gnl, open)
// vérifier que la map est bien un rectangle
// vérifier que les caractères soient correctes : map doit être constitutée des 5 caractères. Au moins un P, un E et un C
// que la map soit bien entourée de murs
// créer une fonction exit qui :
// 		fermer la fenêtre : mlx_destroy_window
// 		mlx :mlx_destroy_display() + free
// 		sprites ( les xpm ) : mlx_destroy_image
// 		free

// 2. initialisation de la struct et de la mlx

// 3. render 
//  analyser la map et afficher en fonction des elements de la map : mlx_put_image_to_window()

// 4. intéractions avec le clavier
// mlx_key_hook() + fct a implenter pour voir si le perso est autorisé à bouger et action si ok ( retirer collectible, ...)

// 5. pour permettre à la map de s'afficher, besoin d'une boucle
// mlx_loop()
// mlx_hook() pour intégrer une fonction pour fermer avec la croix


// COMMANDE DE COMPIL : gcc -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit so_long.c 

#include <stdlib.h>
#include "minilibx_macos/mlx.h"


# define WINDOW_HEIGHT 300
# define WINDOW_WIDTH 600
# define MLX_ERROR 1



typedef struct s_data
{
	void	*mlx_ptr;
	void 	*mlx_win;

}		t_data;

int	handle_no_event(void *data)
{
	return (0);
}

int handle_keypress(int keysym, t_data *data)
{
	if (keysym == 0x001b) 
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);	
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	printf("Keyrelease: %d", keysym);
	return (0);
}

int main(void)
{
	t_data 	data;

// initialisation et création de fenêtre
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
	{
		return (MLX_ERROR);
	}
	data.mlx_win = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	if (data.mlx_win == NULL)
	{
		return (MLX_ERROR);
	}

// Register events before the loop starts = hooks functions


	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data); // exécutée quand pas d'event sinon la boucle ne s'arrête jamais
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &handle_keypress, &data); // fonction exécutée à chaque fois qu'une touche est pressée
	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data); //exécutée à chaque fois qu'une touche est relachée


// loop 

	mlx_loop(data.mlx_ptr);

// clear
	free(data.mlx_ptr);

}


