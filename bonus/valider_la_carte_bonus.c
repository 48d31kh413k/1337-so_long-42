
#include "../include/so_long_bonus.h"
#include "../libft/libft.h"
#include "../printf/ft_printf.h"

void	verifier_la_carte(char *buffer, t_jeu *jeu)
{
	int	x;

	x = ft_strlen(buffer);
	if (jeu->invalide_caractere)
	{
		ft_printf("Error\n Invalide caractere");
		exit(1);
	}
	jeu->carte_zone = x - jeu->carte_y;
	if (buffer[--x] != '\n')
		jeu->carte_y++;
	if (jeu->carte_zone != jeu->carte_x * jeu->carte_y)
	{
		ft_printf("Error!\nLa carte ne contient pas la figure plane adéquate.\n");
		exit (1);
	}
	verifier_la_limite_x(jeu);
	verifier_la_limite_y(jeu);
}

void	verifier_les_caracteres(char *buffer, t_jeu *jeu)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'P')
			jeu->joueur++;
		else if (buffer[i] == 'C')
			jeu->points++;
		else if (buffer[i] == 'E')
			jeu->sortie++;
		else if (buffer[i] == '\n')
			jeu->carte_y++;
		else if (buffer[i] != '0' && buffer[i] != '1' && buffer[i] != 'K')
				jeu->invalide_caractere++;
		i++;
	}
	if (jeu->joueur != 1 || jeu->points < 1 || jeu->sortie != 1)
	{
		ft_printf("Error\n");
		ft_printf("Le nombre des Joueurs, points ou sorties est Incorrect.\n");
		exit(1);
	}
}

char	*ft_join(char *line, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i])
		i++;
	str = malloc(i + 2);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
	return (str);
}

int	verifier(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*obtenir_la_carte(int fd)
{
	char	buffer;
	char	*line;
	int		rd_bytes;

	rd_bytes = 1;
	if (fd < 0)
		line = NULL;
	line = malloc(1);
	line[0] = '\0';
	while (!verifier(line) && rd_bytes > 0)
	{
		rd_bytes = read(fd, &buffer, 1);
		if ((rd_bytes == 0 && line[0] == '\0') || rd_bytes < 0)
		{
			free(line);
			ft_printf("Error\nEmpty map");
			exit(1);
		}
		if (rd_bytes == 0 && line[0] != '\0')
			return (line);
		line = ft_join(line, buffer);
	}
	return (line);
}
