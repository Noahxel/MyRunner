/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** move_elems
*/

#include "../include/my_runner.h"

void move_all_chars(main_t * main, int x_value, int y_value)
{
    main->charac[0].pos.x += x_value;
    main->charac[1].pos.x += x_value;
    main->charac[2].pos.x += x_value;
    main->charac[0].pos.y += y_value;
    main->charac[1].pos.y += y_value;
    main->charac[2].pos.y += y_value;
    sfSprite_setPosition(main->charac[0].sprite, main->charac[0].pos);
    sfSprite_setPosition(main->charac[1].sprite, main->charac[1].pos);
    sfSprite_setPosition(main->charac[2].sprite, main->charac[2].pos);
}

void move_all_chars_to(main_t * main, int x_value, int y_value)
{
    if (x_value != 0) {
        main->charac[0].pos.x = x_value;
        main->charac[1].pos.x = x_value;
        main->charac[2].pos.x = x_value;
    }
    if (y_value != 0) {
        main->charac[0].pos.y = y_value;
        main->charac[1].pos.y = y_value;
        main->charac[2].pos.y = y_value;
    }
    sfSprite_setPosition(main->charac[0].sprite, main->charac[0].pos);
    sfSprite_setPosition(main->charac[1].sprite, main->charac[1].pos);
    sfSprite_setPosition(main->charac[2].sprite, main->charac[2].pos);
}

void check_jump(main_t *main)
{
    if (main->charac[1].pos.y > main->global->ground_hight - 250 &&
    main->charac[1].rect.left <= 71) {
        main->charac[1].pos.y -= 3;
    }
    else if (main->charac[1].pos.y != main->global->ground_hight &&
    main->charac[1].rect.left > 71) {
        main->charac[1].pos.y += 3;
    }
    sfSprite_setPosition(main->charac[1].sprite, main->charac[1].pos);
    sfSprite_setTextureRect(main->charac[1].sprite, main->charac[1].rect);
}

void move_obstacles(main_t *main)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
    (main->global->bloc_cooldown)) >= 2) {
        for (int i = 0; i < main->b_g->bloc_nbr; i++) {
            main->blocs[i].pos.x -= 1;
        }
        sfClock_restart(main->global->bloc_cooldown);
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
    (main->global->spikes_cooldown)) >= 2) {
        for (int i = 0; i < main->s_g->spikes_nbr; i++) {
            main->spikes[i].pos.x -= 1;
        }
        sfClock_restart(main->global->spikes_cooldown);
    }
}

void move_elems(main_t *main)
{
    main->charac[0].pos.y = main->global->ground_hight;
    sfSprite_setPosition(main->charac[0].sprite, main->charac[0].pos);
    main->charac[2].pos.y = main->global->ground_hight;
    sfSprite_setPosition(main->charac[2].sprite, main->charac[2].pos);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(main->global->move_cooldown))
    % 2 == 0) {
        main->paralax[2].pos.x -= 0.5;
    }
    if (main->charac[1].is_active == sfTrue &&
    sfTime_asMilliseconds(sfClock_getElapsedTime
    (main->global->move_cooldown)) % 2 == 0) {
        check_jump(main);
    }
    move_obstacles(main);
    sfSprite_setPosition(main->paralax[2].sprite, main->paralax[2].pos);
}
