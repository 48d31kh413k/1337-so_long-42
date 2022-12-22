
#include "../include/so_long_bonus.h"
#include "../libft/libft.h"
#include "mlx.h"
#include "../printf/ft_printf.h"

void	afficher_les_mouvements(t_jeu *jeu)
{
	char	*s;

	s = ft_itoa(jeu->joueur_mouvement);
	mlx_string_put(jeu->identifiant, jeu->mlx_win,
		jeu->pixel * jeu->carte_x * (0.84), 10, 0x80000,
		"Mouvement: ");
	mlx_string_put(jeu->identifiant, jeu->mlx_win,
		jeu->pixel * jeu->carte_x * (0.95), 10, 0x80000,
		s);
	free(s);
}

void	mettre_ennemie(t_jeu *jeu)
{
	jeu->fichier = mlx_xpm_file_to_image(jeu->identifiant,
			jeu->ennemie_fichier, &jeu->pixel, &jeu->pixel);
	mlx_put_image_to_window (jeu->identifiant, jeu->mlx_win,
		jeu->fichier, jeu->pixel * jeu->x,
		jeu->pixel * jeu->y);
}

void	ft_ennemie(int keyhook, t_jeu *jeu)
{
	if (((keyhook == 2 && jeu->carte[jeu->j_y][jeu->j_x + 1] == 'K')
		|| (keyhook == 1 && jeu->carte[jeu->j_y + 1][jeu->j_x] == 'K')
		|| (keyhook == 0 && jeu->carte[jeu->j_y][jeu->j_x - 1] == 'K')
		|| (keyhook == 13 && jeu->carte[jeu->j_y - 1][jeu->j_x] == 'K')))
	{
		ft_printf("YOU LOSE\n");
		fermer_la_fenetre(jeu);
	}
}

void	farray(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
}

void	ft_c(char *str, char **ptr, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	free(str);
	farray(ptr, count);
}
