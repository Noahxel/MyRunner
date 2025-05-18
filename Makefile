##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## compile main.c and u.t
##

SRCTEST		=		test/test_project.c

SRC		=		src/main.c	\
				src/my_events.c	\
				src/my_runner.c	\
				src/my_setup.c	\
				src/my_draw_sprites.c	\
				src/my_move_paralax_rect.c	\
				src/my_move_char_rect.c	\
				src/set_char_struct.c	\
				src/set_paralax_struct.c	\
				src/manage_display.c	\
				src/move_elems.c	\
				src/extract_str.c	\
				src/map_gestion.c	\
				src/set_obstacles_struct.c	\
				src/obstacle_colision.c	\
				src/main_menu_gestion.c	\
				src/pause_menu_gestion.c	\
				src/display_menus.c	\
				src/display_menus2.c	\
				src/my_neg_endgame_gestion.c	\
				src/my_pos_endgame_gestion.c	\
				src/my_endgame_gestion.c

TEST		=		unit_tests

NAME		=		my_runner

OBJ		=		$(SRC:.c=.o)

LDFLAGS		=		-Llib/my -lmy
CFLAGS		=		-Wall -Wextra
TFLAGS		=		--coverage -lcriterion
GFLAG		=		-l csfml-graphics
WFLAG		=		-l csfml-window
SFLAG		=		-l csfml-system
AFLAGS		=		-l csfml-audio

all:    $(NAME)

$(NAME):		$(OBJ)
		make re -sC lib/my/
		gcc $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS) $(GFLAG) $(AFLAGS) $(SFLAG) $(WFLAG)

tests_run:
		gcc $(CFLAGS) $(SRCTEST) $(SRC) -o $(TEST) $(LDFLAGS) $(TFLAGS)
		./unit_tests

clean:
		rm -f *.o
		rm -f src/*.o
		rm -f $(NAME)
		make clean -sC lib/my/

fclean: clean
		make fclean -sC lib/my/
		rm -f *.gcno
		rm -f *.gcda
		rm -f $(TEST)

re: fclean all
