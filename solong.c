// 1. gérer erreurs et leaks
// verifier le nombre d'arg 
// malloc notre structure
// vérifier les extensions fichier (maps) -------------> FAIT
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


// COMMANDE DE COMPIL : gcc -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit *.c



#include "solong.h"

int main(int ac, char **av)
{
	t_data data;

	data.title = av[1];
	if(ac == 2)
	{
		if(checkextension(data.title) == 0)
			{		

				data.map = create_map(data.title);
				if( check_all(data.title) == 0)
				// rajouter un if avant -> if on arrive a parser la map : init
					init(&data); 
				else
				{
					printf("Error: la map ne remplit pas les conditions requises\n");
					return (0);
				}
			}
	}
}