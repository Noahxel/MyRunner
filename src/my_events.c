/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** my_events
*/

#include "../include/my_runner.h"

void manage_mouse_click(sfRenderWindow *window)
{
    sfVector2i coo;

    coo = sfMouse_getPositionRenderWindow(window);
    printf("Mouse x = %d y = %d\n", coo.x, coo.y);
}

void move_char(main_t *main)
{
    if (main->global->event.type == sfEvtKeyPressed &&
    main->b_g->colision == sfFalse) {
        if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue &&
        (main->global->actual_char->pos.x <= 1900)) {
            move_all_chars(main, 20, 0);
        }
        if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue &&
        (main->global->actual_char->pos.x >= 0)) {
            move_all_chars(main, -20, 0);
        }
    }
}

void analyse_events(main_t *main)
{
    if (main->global->event.type == sfEvtClosed)
        sfRenderWindow_close(main->global->window);
    if (main->global->event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(main->global->window);
    if (main->global->event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue &&
        main->charac[1].is_active == sfFalse) {
            main->charac[1].is_active = sfTrue;
            sfClock_restart(main->charac[1].clock);
        }
        if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue &&
        main->charac[2].is_active == sfFalse) {
            main->charac[2].is_active = sfTrue;
            sfClock_restart(main->charac[2].clock);
        }
        if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
            main->menus[1].is_active = sfTrue;
            pause_menu_gestion(main);
        }
    }
    move_char(main);
}
