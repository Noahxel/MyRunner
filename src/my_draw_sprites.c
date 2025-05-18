/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** my_sprites
*/

#include "../include/my_runner.h"
#include "../include/my.h"

void display_sprite2(main_t *main)
{
    sfRenderWindow_drawSprite(main->global->window,
    main->paralax[1].sprite, NULL);
    sfRenderWindow_drawSprite(main->global->window,
    main->paralax[2].sprite, NULL);
    sfRenderWindow_display(main->global->window);
}

void display_sprite(main_t *main, sfSprite *sprite)
{
    sfRenderWindow_clear(main->global->window, sfBlack);
    sfRenderWindow_drawSprite(main->global->window,
    main->paralax[0].sprite, NULL);
    sfRenderWindow_drawSprite(main->global->window, sprite, NULL);
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
    display_sprite2(main);
}
