/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** display_zat
*/

#include "../include/my_runner.h"


void manage_char_display(main_t* main, charac_t my_char)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(my_char.clock))
    >= my_char.cooldown_rect) {
        move_char_rect(main);
        sfSprite_setTextureRect(my_char.sprite, my_char.rect);
        sfClock_restart(my_char.clock);
    }
}

void manage_paralax_display2(main_t *main, charac_t my_char)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
    (main->paralax[2].clock)) >= 4) {
        sfSprite_setTextureRect(main->paralax[2].sprite,
        main->paralax[2].rect);
        move_crow_rect(main, 0, 76);
        if (main->paralax[2].pos.x <= -200) {
            main->paralax[2].pos.x = 1950;
            main->paralax[2].pos.y = 0 + rand() % 250;
        }
    }
    manage_char_display(main, my_char);
}

void manage_paralax_display(main_t *main, charac_t my_char)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
    (main->paralax[0].clock)) >= 15) {
        sfSprite_setTextureRect(main->paralax[0].sprite,
        main->paralax[0].rect);
        move_back_rect(main, 3840, 1);
        sfClock_restart(main->paralax[0].clock);
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
    (main->paralax[1].clock)) >= 2) {
        sfSprite_setTextureRect(main->paralax[1].sprite,
        main->paralax[1].rect);
        move_ground_rect(main, 1915, 2);
        main->paralax[1].pos.x -= 2;
        sfClock_restart(main->paralax[1].clock);
    }
    manage_paralax_display2(main, my_char);
}
