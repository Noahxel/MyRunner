/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** set_obstacles_struct
*/

#include "../include/my_runner.h"

bloc_gestion_t *set_bloc_struct(void)
{
    bloc_gestion_t *b_g = malloc(sizeof(bloc_gestion_t));

    b_g->colision = sfFalse;
    b_g->end_bloc = sfFalse;
    b_g->bloc_found = 0;
    b_g->bloc_nbr = 0;
    b_g->tmp_y = 0;
    b_g->tmp_x = 0;
    return (b_g);
}

spikes_gestion_t *set_spikes_struct(void)
{
    spikes_gestion_t *s_g = malloc(sizeof(spikes_gestion_t));

    s_g->colision = sfFalse;
    s_g->spikes_found = 0;
    s_g->spikes_nbr = 0;
    s_g->tmp_y = 0;
    s_g->tmp_x = 0;
    return (s_g);
}

spikes_t set_spikes(int x, int y)
{
    spikes_t spike;
    sfIntRect rect = {0, 0, 200, 80};
    sfVector2f pos = {x, y + 20};
    sfVector2f resize = {1, 1};

    spike.resize = resize;
    spike.rect = rect;
    spike.pos = pos;
    spike.clock = sfClock_create();
    spike.sprite = sfSprite_create();
    spike.text = sfTexture_createFromFile("my_png/spikes.png", NULL);
    sfSprite_setPosition(spike.sprite, spike.pos);
    sfSprite_setTexture(spike.sprite, spike.text, sfFalse);
    sfSprite_setTextureRect(spike.sprite, spike.rect);
    sfSprite_setScale(spike.sprite, resize);
    return (spike);
}

blocs_t set_bloc(int x, int y)
{
    blocs_t bloc;
    sfIntRect rect = {0, 0, 200, 100};
    sfVector2f pos = {x, y};
    sfVector2f resize = {1, 1};

    bloc.resize = resize;
    bloc.rect = rect;
    bloc.pos = pos;
    bloc.clock = sfClock_create();
    bloc.sprite = sfSprite_create();
    if (y >= 800)
        bloc.text = sfTexture_createFromFile("my_png/ground_bloc.png", NULL);
    else
        bloc.text = sfTexture_createFromFile("my_png/sky_bloc.png", NULL);
    sfSprite_setPosition(bloc.sprite, bloc.pos);
    sfSprite_setTexture(bloc.sprite, bloc.text, sfFalse);
    sfSprite_setTextureRect(bloc.sprite, bloc.rect);
    sfSprite_setScale(bloc.sprite, resize);
    return (bloc);
}
