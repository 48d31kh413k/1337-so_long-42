
#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_zelda
{
	void	*identifiant;
	void	*mlx_win;
	char	**carte;
	char	*fichier;
	int		carte_x;
	int		carte_y;
	int		carte_zone;
	int		x;
	int		y;
	int		pixel;
	int		joueur;
	int		j_x;
	int		j_y;
	int		joueur_mouvement;
	char	*joueur_direction;
	int		points;
	int		sortie;
	int		point_chemin;
	int		sortie_chemin;
	int		invalide_caractere;
}	t_jeu;

void	verifier_arg(int argc, char **argv);
void	initialisation(t_jeu *jeu);
void	valider_la_carte(char **argv, t_jeu *jeu);
void	la_fenetre(t_jeu *jeu);
char	*obtenir_la_carte(int fd);
int		verifier(char *line);
char	*ft_join(char	*line, char c);
void	verifier_les_caracteres(char *buffer, t_jeu *jeu);
void	verifier_la_carte(char *buffer, t_jeu *jeu);
void	verifier_la_limite_y(t_jeu *jeu);
void	verifier_la_limite_x(t_jeu *jeu);
void	erreur_des_limites(void);
void	remplir_la_fenetre(t_jeu *jeu);
int		max_points(t_jeu *jeu);
void	remplir_la_surface(t_jeu *jeu);
int		fermer_la_fenetre(t_jeu *jeu);
void	mettre_les_limites(t_jeu *jeu);
void	mettre_la_surface(t_jeu *jeu);
void	mettre_les_points(t_jeu *jeu);
void	mettre_le_joueur(t_jeu *jeu);
void	mettre_la_sortie(t_jeu *jeu);
int		clavier(int keyhook, t_jeu *jeu);
void	haut(t_jeu *jeu);
void	bas(t_jeu *jeu);
void	gauche(t_jeu *jeu);
void	droite(t_jeu *jeu);
void	valider_le_chemin(int y, int x, t_jeu *jeu);
void	verifier_le_chemin(t_jeu *jeu);
void	farray(char **ptr, int i);
void	ft_c(char *str, char **ptr, char c);

#endif
