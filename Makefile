NAME		= so_long
BNAME		= so_long_bonus
INC			= inc
INC		= -I include
LIBFT		= libft
PRINTF		= printf
MINILIBX	= mlx
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rf
LINKS	    = -I /usr/localinclude -L /usr/local/lib -lmlx \
		      -framework OpenGL -framework AppKit
SRC_DIR		= 	src/
MAND_FILES	=	so_long valider_la_carte verifier_les_limites la_fenetre remplir_la_fenetre crochet verifier_le_chemin utils
BONUS_DIR	=	bonus/
BONUS_FILES	=	so_long_bonus valider_la_carte_bonus verifier_les_limites_bonus \
				la_fenetre_bonus remplir_la_fenetre_bonus crochet_bonus utils_bonus \
				verifier_le_chemin_bonus
SRC_FILES	=	$(addprefix $(SRC_DIR), $(MAND_FILES))
SRC_BFILES	=	$(addprefix $(BONUS_DIR), $(BONUS_FILES))
SRC 		= 	$(addsuffix .c, $(SRC_FILES))
OBJ 		= 	$(addsuffix .o, $(SRC_FILES))
SRCB		=	$(addsuffix .c, $(SRC_BFILES))
OBJB		=	$(addsuffix .o, $(SRC_BFILES))


all:		$(NAME)

$(NAME):	$(OBJ)
			@make -s -C $(LIBFT)
			@make -s -C $(PRINTF)
			$(CC) $(CFLAGS) $(OBJ) $(HEADER) $(LIBFT)/libft.a  $(PRINTF)/libftprintf.a $(LINKS) -o $(NAME)

bonus:	$(BNAME)

$(BNAME):	$(OBJB)
			@make -s -C $(LIBFT)
			@make -s -C $(PRINTF)
			$(CC) $(CFLAGS) $(SRCB) $(HEADER) $(LIBFT)/libft.a $(PRINTF)/libftprintf.a $(LINKS) -o $(BNAME)

clean:
			@make clean -C $(LIBFT)
			@make clean -C $(PRINTF)
			$(RM) $(OBJ)
			$(RM) $(OBJB)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(BNAME)
			@$(RM) $(LIBFT)/libft.a
			@$(RM) $(PRINTF)/libftprintf.a

re:			fclean all

.PHONY:		all bonus clean fclean re 
