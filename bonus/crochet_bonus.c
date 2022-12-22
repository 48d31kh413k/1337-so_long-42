
#include "../include/so_long_bonus.h"
#include "../printf/ft_printf.h"

void	haut(t_jeu *jeu)
{
	jeu->carte[jeu->j_y][jeu->j_x] = '0';
	jeu->carte[jeu->j_y - 1][jeu->j_x] = 'P';
	jeu->joueur_mouvement++;
	remplir_la_fenetre(jeu);
}

void	bas(t_jeu *jeu)
{
	jeu->carte[jeu->j_y][jeu->j_x] = '0';
	jeu->carte[jeu->j_y + 1][jeu->j_x] = 'P';
	jeu->joueur_mouvement++;
	remplir_la_fenetre(jeu);
}

void	gauche(t_jeu *jeu)
{
	jeu->carte[jeu->j_y][jeu->j_x] = '0';
	jeu->carte[jeu->j_y][jeu->j_x - 1] = 'P';
	jeu->joueur_mouvement++;
	remplir_la_fenetre(jeu);
}

void	droite(t_jeu *jeu)
{
	jeu->carte[jeu->j_y][jeu->j_x] = '0';
	jeu->carte[jeu->j_y][jeu->j_x + 1] = 'P';
	if (jeu)
	jeu->joueur_mouvement++;
	remplir_la_fenetre(jeu);
}

int	clavier(int keyhook, t_jeu *jeu)
{
	if (keyhook == 53)
		fermer_la_fenetre(jeu);
	ft_ennemie(keyhook, jeu);
	if (jeu->points == 0
		&& ((keyhook == 2 && jeu->carte[jeu->j_y][jeu->j_x + 1] == 'E')
		|| (keyhook == 1 && jeu->carte[jeu->j_y + 1][jeu->j_x] == 'E')
		|| (keyhook == 0 && jeu->carte[jeu->j_y][jeu->j_x - 1] == 'E')
		|| (keyhook == 13 && jeu->carte[jeu->j_y - 1][jeu->j_x] == 'E')))
	{
		ft_printf("YOU WIN\n");
		fermer_la_fenetre(jeu);
	}
	if (keyhook == 13 && jeu->carte[jeu->j_y - 1][jeu->j_x] != '1'
		&& jeu->carte[jeu->j_y - 1][jeu->j_x] != 'E')
		haut(jeu);
	if (keyhook == 0 && jeu->carte[jeu->j_y][jeu->j_x - 1] != '1'
		&& jeu->carte[jeu->j_y][jeu->j_x - 1] != 'E')
		gauche(jeu);
	if (keyhook == 1 && jeu->carte[jeu->j_y + 1][jeu->j_x] != '1'
		&& jeu->carte[jeu->j_y + 1][jeu->j_x] != 'E')
		bas(jeu);
	if (keyhook == 2 && jeu->carte[jeu->j_y][jeu->j_x + 1] != '1'
		&& jeu->carte[jeu->j_y][jeu->j_x + 1] != 'E')
		droite(jeu);
	return (0);
}
