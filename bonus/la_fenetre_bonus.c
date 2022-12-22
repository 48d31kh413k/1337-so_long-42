
#include "../include/so_long_bonus.h"
#include "mlx.h"

int	fermer_la_fenetre(t_jeu *jeu)
{
	mlx_destroy_window(jeu->identifiant, jeu->mlx_win);
	exit(1);
	return (0);
}

void	remplir_la_surface(t_jeu *jeu)
{
	jeu->y = 0;
	while ((jeu->y) < (jeu->carte_y))
	{
		jeu->x = 0;
		while ((jeu->x) < (jeu->carte_x))
		{
			jeu->fichier = mlx_xpm_file_to_image(jeu->identifiant,
					"./images/surface.xpm", &jeu->pixel, &jeu->pixel);
			mlx_put_image_to_window (jeu->identifiant, jeu->mlx_win,
				jeu->fichier, jeu->pixel * jeu->x,
				jeu->pixel * jeu->y);
			jeu->x++;
		}
		jeu->y++;
	}
}

int	max_points(t_jeu *jeu)
{
	int	i;

	i = 0;
	jeu->y = 0;
	while ((jeu->y) < (jeu->carte_y))
	{
		jeu->x = 0;
		while ((jeu->x) < (jeu->carte_x))
		{
			if (jeu->carte[jeu->y][jeu->x] == 'C')
				i++;
			jeu->x++;
		}
		jeu->y++;
	}
	return (i);
}

void	remplir_la_fenetre(t_jeu *jeu)
{
	jeu->points = max_points(jeu);
	remplir_la_surface(jeu);
	jeu->y = 0;
	while ((jeu->y) < (jeu->carte_y))
	{
		jeu->x = 0;
		while ((jeu->x) < (jeu->carte_x))
		{
			if (jeu->carte[jeu->y][jeu->x] == '1')
				mettre_les_limites(jeu);
			if (jeu->carte[jeu->y][jeu->x] == 'C')
				mettre_les_points(jeu);
			if (jeu->carte[jeu->y][jeu->x] == 'P')
				mettre_le_joueur(jeu);
			if (jeu->carte[jeu->y][jeu->x] == 'E')
				mettre_la_sortie(jeu);
			if (jeu->carte[jeu->y][jeu->x] == 'K')
				mettre_ennemie(jeu);
			jeu->x++;
		}
		jeu->y++;
	}
	afficher_les_mouvements(jeu);
}
