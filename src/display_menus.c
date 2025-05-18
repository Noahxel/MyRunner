/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** display_menus
*/

#include "../include/my_runner.h"

void display_pause_menu2(main_t *main)
{
    sfRenderWindow_drawSprite(main->global->window,
    main->paralax[1].sprite, NULL);
    sfRenderWindow_drawSprite(main->global->window,
    main->paralax[2].sprite, NULL);
    sfRenderWindow_drawSprite(main->global->window,
    main->menus[1].menu_sprite, NULL);
    sfRenderWindow_drawSprite(main->global->window,
    main->menus[1].button1_sprite, NULL);
    sfRenderWindow_drawSprite(main->global->window,
    main->menus[1].button2_sprite, NULL);
    sfRenderWindow_display(main->global->window);
}

void display_pause_menu(main_t *main)
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
    display_pause_menu2(main);
}

void display_main_menu(main_t *main)
{
    sfRenderWindow_clear(main->global->window, sfBlack);
    sfRenderWindow_drawSprite(main->global->window,
    main->menus[0].menu_back_sprite, NULL);
    sfRenderWindow_drawSprite(main->global->window,
    main->menus[0].menu_sprite, NULL);
     sfRenderWindow_drawSprite(main->global->window,
     main->menus[0].button1_sprite, NULL);
      sfRenderWindow_drawSprite(main->global->window,
      main->menus[0].button2_sprite, NULL);
    sfRenderWindow_display(main->global->window);
}

void display_neg_endgame_menu2(main_t *main)
{
    sfRenderWindow_drawSprite(main->global->window,
    main->paralax[1].sprite, NULL);
    sfRenderWindow_drawSprite(main->global->window,
    main->paralax[2].sprite, NULL);
    sfRenderWindow_drawSprite(main->global->window,
    main->menus[2].menu_sprite, NULL);
    sfRenderWindow_drawSprite(main->global->window,
    main->menus[2].button2_sprite, NULL);
    sfRenderWindow_display(main->global->window);
}

void display_neg_endgame_menu(main_t *main)
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
    display_neg_endgame_menu2(main);
}