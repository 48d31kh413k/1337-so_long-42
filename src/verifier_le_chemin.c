
#include "../include/so_long.h"
#include "../printf/ft_printf.h"

void	valider_le_chemin(int y, int x, t_jeu *jeu)
{
	if (jeu->carte[y][x] == 'E')
		jeu->sortie_chemin++;
	if (y < 0 || y > jeu->carte_y || x < 0 || x > jeu->carte_x
		|| jeu->carte[y][x] == '1' || jeu->carte[y][x] == 'E')
		return ;
	if (jeu->carte[y][x] == 'C')
		jeu->point_chemin++;
	jeu->carte[y][x] = '1';
	valider_le_chemin(y, (x - 1), jeu);
	valider_le_chemin(y, (x + 1), jeu);
	valider_le_chemin((y - 1), x, jeu);
	valider_le_chemin((y + 1), x, jeu);
	return ;
}

void	verifier_le_chemin(t_jeu *jeu)
{
	jeu->y = 0;
	while ((jeu->y) < (jeu->carte_y))
	{
	jeu->x = 0;
		while ((jeu->x) < (jeu->carte_x))
		{
			if (jeu->carte[jeu->y][jeu->x] == 'P')
			{
				valider_le_chemin(jeu->y, jeu->x, jeu);
				if (jeu->points == jeu->point_chemin && jeu->sortie_chemin)
				{
					jeu->x = 0;
					jeu->y = 0;
					return ;
				}
				else
				{
					ft_printf("Error\n Il n'y a pas de chemin valide");
					exit(1);
				}
			}
			jeu->x++;
		}
		jeu->y++;
	}
}
