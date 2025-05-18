/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** my_setup
*/

#include "../include/my_runner.h"

global_t *set_global(main_t *main)
{
    global_t *global = malloc(sizeof(global_t));
    sfVideoMode videomode = {1920, 1080, 30};

    global->ground_hight = 800;
    global->len_map = 0;
    global->neg_endgame = sfFalse;
    global->pos_endgame = sfFalse;
    global->actual_char = &main->charac[0];
    global->bloc_cooldown = sfClock_create();
    global->spikes_cooldown = sfClock_create();
    global->move_cooldown = sfClock_create();
    global->event_cooldoxn = sfClock_create();
    global->window = sfRenderWindow_create(videomode,
    "Konoha_Runner", sfClose | sfResize, NULL);
    return (global);
}

main_t *my_setup(void)
{
    main_t *main = malloc(sizeof(main_t));
    main->charac = malloc(sizeof(charac_t) * 3);
    main->paralax = malloc(sizeof(paralax_t) * 3);
    main->menus = malloc(sizeof(menu_t) * 4);

    main->s_g = set_spikes_struct();
    main->b_g = set_bloc_struct();
    main->menus[0] = set_main_menu();
    main->menus[1] = set_pause_menu();
    main->menus[2] = set_negative_ending();
    main->menus[3] = set_positive_ending();
    main->charac[0] = set_char();
    main->charac[1] = set_jump();
    main->charac[2] = set_roll();
    main->paralax[0] = set_back();
    main->paralax[1] = set_ground();
    main->paralax[2] = set_crow();
    main->global = set_global(main);
    return (main);
}
