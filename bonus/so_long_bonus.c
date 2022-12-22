
#include "../include/so_long_bonus.h"
#include "../libft/libft.h"
#include "mlx.h"
#include "../printf/ft_printf.h"

void	la_fenetre(t_jeu *jeu)
{
	jeu->pixel = 50;
	jeu->identifiant = mlx_init();
	jeu->mlx_win = mlx_new_window(jeu->identifiant,
			jeu->pixel * jeu->carte_x,
			jeu->pixel * jeu->carte_y, "The Legend of Zelda");
	remplir_la_fenetre(jeu);
}

void	valider_la_carte(char **argv, t_jeu *jeu)
{
	int		fd;
	char	*buffer;
	char	**carte_x;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error!\nImpossible de lire le fichier.\n");
		exit (1);
	}
	buffer = obtenir_la_carte(fd);
	verifier_les_caracteres(buffer, jeu);
	jeu->carte = ft_split(buffer, '\n');
	carte_x = jeu->carte;
	while (jeu->carte[0][jeu->carte_x] != '\0')
		jeu->carte_x++;
	verifier_la_carte(buffer, jeu);
	verifier_le_chemin(jeu);
	jeu->carte = ft_split(buffer, '\n');
	ft_c(buffer, carte_x, '\n');
	close(fd);
}

void	initialisation(t_jeu *jeu)
{
	jeu->carte_x = 0;
	jeu->carte_y = 0;
	jeu->carte_zone = 0;
	jeu->x = 0;
	jeu->y = 0;
	jeu->pixel = 0;
	jeu->joueur = 0;
	jeu->joueur_mouvement = 0;
	jeu->joueur_direction = "./images/bas.xpm";
	jeu->points = 0;
	jeu->sortie = 0;
	jeu->ennemie_fichier = "./images/enemy2.xpm";
}

void	ft_verifier_arg(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
	{
		ft_printf("Error\n Le nombre d'argument est invalide.\n");
		exit(0);
	}
	len = ft_strlen(argv[1]);
	if (!(argv[1][len - 4] == '.' && argv[1][len - 3] == 'b' && \
		argv[1][len - 2] == 'e' && argv[1][len - 1] == 'r'))
	{
		ft_printf("Error\n");
		ft_printf("L'extension du fichier est invalide,");
		ft_printf(" veuillez insérer un fichier de type .ber\n");
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	t_jeu	jeu;

	ft_verifier_arg(argc, argv);
	initialisation(&jeu);
	valider_la_carte(argv, &jeu);
	la_fenetre(&jeu);
	mlx_hook(jeu.mlx_win, 2, 0, clavier, &jeu);
	mlx_hook(jeu.mlx_win, 17, 0, fermer_la_fenetre, &jeu);
	mlx_loop_hook(jeu.identifiant, animation, &jeu);
	mlx_loop(jeu.identifiant);
	exit(0);
	return (0);
}
