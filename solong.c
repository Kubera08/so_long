// 1. gérer erreurs et leaks
// verifier le nombre d'arg 
// malloc notre structure 
// vérifier les extensions fichier (maps) -------------> FAIT
// ouvrir les fichiers maps (gnl, open) -----> FAIT
// vérifier que la map est bien un rectangle ------> FAIT
// vérifier que les caractères soient correctes : map doit être constitutée des 5 caractères. Au moins un P, un E et un C ----> FAIT
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


// COMMANDE DE COMPIL : gcc solong.c ./minilibx-linux/libmlx_Linux.a -lXext -lX11 -I ./minilibx



#include "solong.h"

int main(int ac, char **av)
{
	if(ac == 2)
	{
		if( checkextension(av[1]) == 0)
			{
				if( check_all(av[1]) == 0)
					init();
				else
				{
					printf("Error: la map ne remplit pas les conditions requises\n");
					return (0);
				}
			}
	}
}
