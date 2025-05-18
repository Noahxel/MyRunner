/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** my_endgame_gestion
*/

#include "../include/my_runner.h"

void my_endgame_gestion(main_t *main)
{
    if (main->global->neg_endgame == sfTrue)
        negative_ending_gestion(main);
    if (main->global->pos_endgame == sfTrue) {
        positive_ending_gestion(main);
    }
}