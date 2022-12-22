
#include "../include/so_long.h"
#include "../printf/ft_printf.h"
#include "mlx.h"

void	mettre_les_limites(t_jeu *jeu)
{
	jeu->fichier = mlx_xpm_file_to_image(jeu->identifiant,
			"./images/arbre.xpm", &jeu->pixel, &jeu->pixel);
	if (!jeu->fichier)
	{
		ft_printf("Error\nImpossible de lire l image.\n");
		exit(1);
	}
	mlx_put_image_to_window (jeu->identifiant, jeu->mlx_win,
		jeu->fichier, jeu->pixel * jeu->x,
		jeu->pixel * jeu->y);
}

void	mettre_la_surface(t_jeu *jeu)
{
	jeu->fichier = mlx_xpm_file_to_image(jeu->identifiant,
			"./images/surface.xpm", &jeu->pixel, &jeu->pixel);
	if (!jeu->fichier)
	{
		ft_printf("Error\nImpossible de lire l image.\n");
		exit(1);
	}
	mlx_put_image_to_window (jeu->identifiant, jeu->mlx_win,
		jeu->fichier, jeu->pixel * jeu->x,
		jeu->pixel * jeu->y);
}

void	mettre_les_points(t_jeu *jeu)
{
	jeu->fichier = mlx_xpm_file_to_image(jeu->identifiant,
			"./images/point.xpm", &jeu->pixel, &jeu->pixel);
	if (!jeu->fichier)
	{
		ft_printf("Error\nImpossible de lire l image.\n");
		exit(1);
	}
	mlx_put_image_to_window (jeu->identifiant, jeu->mlx_win,
		jeu->fichier, jeu->pixel * jeu->x,
		jeu->pixel * jeu->y);
	jeu->points++;
}

void	mettre_le_joueur(t_jeu *jeu)
{
	jeu->fichier = mlx_xpm_file_to_image(jeu->identifiant,
			jeu->joueur_direction, &jeu->pixel, &jeu->pixel);
	if (!jeu->fichier)
	{
		ft_printf("Error\nImpossible de lire l image.\n");
		exit(1);
	}
	jeu->j_y = jeu->y;
	jeu->j_x = jeu->x;
	mlx_put_image_to_window (jeu->identifiant, jeu->mlx_win,
		jeu->fichier, jeu->pixel * jeu->x,
		jeu->pixel * jeu->y);
}

void	mettre_la_sortie(t_jeu *jeu)
{
	if (jeu->points == 0)
		jeu->fichier = mlx_xpm_file_to_image(jeu->identifiant,
				"./images/sortie.xpm", &jeu->pixel, &jeu->pixel);
	else
		jeu->fichier = mlx_xpm_file_to_image(jeu->identifiant,
				"./images/bloque.xpm", &jeu->pixel, &jeu->pixel);
	if (!jeu->fichier)
	{
		ft_printf("Error\nImpossible de lire l image.\n");
		exit(1);
	}
	mlx_put_image_to_window (jeu->identifiant, jeu->mlx_win,
		jeu->fichier, jeu->pixel * jeu->x,
		jeu->pixel * jeu->y);
}
