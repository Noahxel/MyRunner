/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** obstacle_gestion
*/

#include "../include/my_runner.h"

void spikes_col(main_t *main, int i)
{
    if (main->global->actual_char->pos.x < main->spikes[i].pos.x + main->spikes[i].rect.width &&
    main->global->actual_char->pos.x + main->global->actual_char->rect.width > main->spikes[i].pos.x &&
    main->global->actual_char->pos.y < main->spikes[i].pos.y + main->spikes[i].rect.width &&
    main->global->actual_char->pos.y + main->global->actual_char->rect.width > main->spikes[i].pos.y) {
        main->global->neg_endgame = sfTrue;
    }
}

void check_blocs_colision(main_t *main)
{
    for (int i = 0; i < main->s_g->spikes_nbr; i++) {
        spikes_col(main, i);
    }
}