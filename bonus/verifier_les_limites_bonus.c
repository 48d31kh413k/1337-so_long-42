
#include "../include/so_long_bonus.h"
#include "../printf/ft_printf.h"

void	erreur_des_limites(void)
{
	ft_printf("Error!\nLe nombre d'arbres est insuffisant.\n");
	ft_printf("Veuillez plantez l'arbre dans l'emplacement concernés.\n");
	exit(1);
}

void	verifier_la_limite_x(t_jeu *jeu)
{
	while ((jeu->x) < (jeu->carte_x))
	{
		if (jeu->carte[0][jeu->x] != '1')
			erreur_des_limites();
		jeu->x++;
	}
	jeu->y = jeu->carte_y - 1;
	jeu->x = 0;
	while ((jeu->x) < (jeu->carte_x))
	{
		if (jeu->carte[jeu->y][jeu->x] != '1')
			erreur_des_limites();
		jeu->x++;
	}
}

void	verifier_la_limite_y(t_jeu *jeu)
{
	jeu->x = 0;
	jeu->y = 0;
	while ((jeu->y) < (jeu->carte_y))
	{
		if (jeu->carte[jeu->y][0] != '1')
			erreur_des_limites();
		jeu->y++;
	}
	jeu->y = 0;
	jeu->x = jeu->carte_x - 1;
	while ((jeu->y) < (jeu->carte_y))
	{
		if (jeu->carte[jeu->y][jeu->x] != '1')
			erreur_des_limites();
		jeu->y++;
	}
}
