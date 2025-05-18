/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** my_move_rect
*/

#include "../include/my_runner.h"

void move_char_rect2(main_t *main)
{
    if (main->charac[0].rect.left >= 432)
        main->charac[0].rect.left = 0;
    else
        main->charac[0].rect.left += 90;
}

void move_char_rect(main_t *main)
{
    if (main->charac[1].is_active == sfTrue) {
        if (main->charac[1].rect.left >= 300) {
            main->charac[1].cooldown_rect = 175;
            main->charac[1].pos.y = main->global->ground_hight;
            main->charac[1].rect.left = 0;
            main->charac[1].is_active = sfFalse;
            return;
        } else if (main->charac[1].rect.left >= 200)
            main->charac[1].cooldown_rect = 100;
        main->charac[1].rect.left += 71;
    } else if (main->charac[2].is_active == sfTrue) {
        if (main->charac[2].rect.left >= 675) {
            main->charac[2].rect.left = 0;
            main->charac[2].is_active = sfFalse;
        } else
            main->charac[2].rect.left += 75;
    } else
        move_char_rect2(main);
}
