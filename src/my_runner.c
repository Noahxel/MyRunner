/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** my_hunter
*/

#include "../include/my_runner.h"
#include "../include/my.h"

void my_runner2(main_t *main)
{
    if (-(main->paralax[1].pos.x) + main->global->actual_char->pos.x
     >= main->global->win_point) {
        main->global->pos_endgame = sfTrue;
     }
    check_blocs_colision(main);
    move_elems(main);
}

void my_runner(main_t *main)
{
    while (sfRenderWindow_pollEvent(main->global->window,
    &main->global->event))
        analyse_events(main);
    if (main->charac[2].is_active == sfTrue) {
        main->global->actual_char = &main->charac[2];
        display_sprite(main, main->charac[2].sprite);
        manage_paralax_display(main, main->charac[2]);
    } else if (main->charac[1].is_active == sfTrue) {
        main->global->actual_char = &main->charac[1];
        display_sprite(main, main->charac[1].sprite);
        manage_paralax_display(main, main->charac[1]);
    } else {
        main->global->actual_char = &main->charac[0];
        display_sprite(main, main->charac[0].sprite);
        manage_paralax_display(main, main->charac[0]);
    }
    my_runner2(main);
}
