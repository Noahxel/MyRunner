/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** my_move_rect
*/

#include "../include/my_runner.h"

void move_ground_rect(main_t *main, int max, int decal)
{
    if (main->paralax[1].rect.left >= max)
        main->paralax[1].rect.left = 0;
    else
        main->paralax[1].rect.left += decal;
}

void move_back_rect(main_t *main, int max, int decal)
{
    if (main->paralax[0].rect.left >= max)
        main->paralax[0].rect.left = 0;
    else
        main->paralax[0].rect.left += decal;
}

void move_crow_rect(main_t *main, int max, int decal)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
    (main->paralax[2].clock)) >= 75) {
        if (main->paralax[2].rect.left == max)
            main->paralax[2].rect.left = 532;
        else
            main->paralax[2].rect.left -= decal;
        sfClock_restart(main->paralax[2].clock);
    }
}