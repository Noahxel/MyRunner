/*
** EPITECH PROJECT, 2021
** DevPack
** File description:
** main
*/

#include "../include/my_runner.h"

int check_errors(int argc, char **argv)
{
    if (argc != 2)
        return (84);
    if (my_strcmp(argv[1], "-h") == 0) {
        my_putstr("\n\t\t[WELCOME]\n\n1. just execute ./my_runner [Map]");
        my_putstr("to play, [Map] is a txt format\n");
        my_putstr("1. To win you have to reach the end of your own map\n");
        my_putstr("2. ! Spikes can kill you\n 3. if you crash,");
        my_putstr("consider it as a win ^^\n");
        my_putstr("\nGood Game !\n");
        return (0);
    }
    return (1);
}

void main2(main_t *main)
{
    while (sfRenderWindow_isOpen(main->global->window)) {
        while (main->menus[0].is_active == sfTrue &&
        sfRenderWindow_isOpen(main->global->window)) {
            main_menu_gestion(main);
        }
        while (main->global->neg_endgame == sfFalse &&
        main->global->pos_endgame == sfFalse &&
        sfRenderWindow_isOpen(main->global->window))
            my_runner(main);
        while (main->global->neg_endgame == sfTrue ||
        main->global->neg_endgame == sfTrue)
            my_endgame_gestion(main);
    }
}

int main(int argc, char **argv)
{
    main_t *main;
    int check = map_gestion(argv[1]);
    int c_e = check_errors(argc, argv);

    if (check || c_e == 84)
        return (84);
    if (c_e == 0)
        return (0);
    main = my_setup();
    main->global->str_map = extract_str(argv[1]);
    obstacles_setup(main);
    main2(main);
    return (0);
}
