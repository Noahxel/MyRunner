/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** display_menus
*/

#include "../include/my_runner.h"

void display_pos_endgame_menu2(main_t *main)
{
    sfRenderWindow_drawSprite(main->global->window,
    main->paralax[1].sprite, NULL);
    sfRenderWindow_drawSprite(main->global->window,
    main->paralax[2].sprite, NULL);
    sfRenderWindow_drawSprite(main->global->window,
    main->menus[3].menu_sprite, NULL);
    //sfRenderWindow_drawSprite(main->global->window,
    //main->menus[3].button1_sprite, NULL);
    sfRenderWindow_drawSprite(main->global->window,
    main->menus[3].button2_sprite, NULL);
    sfRenderWindow_display(main->global->window);
}

void display_pos_endgame_menu(main_t *main)
{
    sfRenderWindow_clear(main->global->window, sfBlack);
    sfRenderWindow_drawSprite(main->global->window,
    main->paralax[0].sprite, NULL);
    sfRenderWindow_drawSprite(main->global->window,
    main->global->actual_char->sprite, NULL);
    for (int i = 0; i < main->b_g->bloc_nbr; i++) {
        sfSprite_setPosition(main->blocs[i].sprite, main->blocs[i].pos);
        sfSprite_setTextureRect(main->blocs[i].sprite, main->blocs[i].rect);
        sfRenderWindow_drawSprite(main->global->window,
        main->blocs[i].sprite, NULL);
    }
    for (int i = 0; i < main->s_g->spikes_nbr; i++) {
        sfSprite_setPosition(main->spikes[i].sprite, main->spikes[i].pos);
        sfSprite_setTextureRect(main->spikes[i].sprite, main->spikes[i].rect);
        sfRenderWindow_drawSprite(main->global->window,
        main->spikes[i].sprite, NULL);
    }
    display_pos_endgame_menu2(main);
}