/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** my_pos_endgame_gestion
*/

#include "../include/my_runner.h"

menu_t set_posative_ending3(menu_t pos_end)
{
    sfSprite_setTexture(pos_end.menu_sprite, pos_end.menu_text, sfFalse);
    sfSprite_setTexture(pos_end.button2_sprite, pos_end.button2_text, sfFalse);
    sfSprite_setTexture(pos_end.menu_back_sprite, pos_end.menu_back_text, sfFalse);
    sfSprite_setPosition(pos_end.menu_sprite, pos_end.menu_original_pos);
    sfSprite_setPosition(pos_end.button2_sprite, pos_end.button2_original_pos);
    sfSprite_setScale(pos_end.menu_sprite, pos_end.menu_resize);
    sfSprite_setScale(pos_end.button2_sprite, pos_end.button2_resize);
    return (pos_end);
}

menu_t set_posative_ending2(menu_t pos_end)
{
    sfIntRect play_rect = {0, 0, 384, 316};
    sfIntRect pos_end_rect = {0, 0, 487, 68};
    sfIntRect pos_end_back_rect = {0, 0, 1920, 1080};

    pos_end.is_active = sfTrue;
    pos_end.button2_text = sfTexture_createFromFile("my_png/quit.png",
    &play_rect);
    pos_end.menu_text = sfTexture_createFromFile("my_png/you_won.png",
    &pos_end_rect);
    sfSprite_setTextureRect(pos_end.menu_sprite, pos_end_rect);
    sfSprite_setTextureRect(pos_end.button2_sprite, play_rect);
    sfSprite_setTextureRect(pos_end.menu_back_sprite, pos_end_back_rect);
    return (set_posative_ending3(pos_end));
}

menu_t set_positive_ending(void)
{
    menu_t pos_end;
    sfVector2f quit_btn_pos = {950, 600};
    sfVector2f quit_resize = {1, 1};
    sfVector2f pos_end_pos = {650, 300};
    sfVector2f resize_pos_end = {1, 1};

    pos_end.button2_sprite = sfSprite_create();
    pos_end.menu_sprite = sfSprite_create();
    pos_end.menu_back_sprite = sfSprite_create();
    pos_end.menu_name = "pos_end menu";
    pos_end.menu_original_pos = pos_end_pos;
    pos_end.menu_resize = resize_pos_end;
    pos_end.button2_original_pos = quit_btn_pos;
    pos_end.button2_resize = quit_resize;
    return (set_posative_ending2(pos_end));
}

void analyse_pos_endgame_events(main_t *main)
{
    sfVector2i coo;

    coo = sfMouse_getPositionRenderWindow(main->global->window);
    if (((coo.x >= main->menus[1].button2_original_pos.x)
    && (coo.x <= (main->menus[1].button2_original_pos.x + 384)))
    && ((coo.y >= main->menus[1].button2_original_pos.y)
    && (coo.y <= (main->menus[1].button2_original_pos.y + 316)))) {
        if (main->menus[1].menu_events.type == sfEvtMouseButtonPressed)
            sfRenderWindow_close(main->global->window);
    } else
        display_pos_endgame_menu(main);
    if (main->menus[1].menu_events.type == sfEvtClosed)
        sfRenderWindow_close(main->global->window);
}

void positive_ending_gestion(main_t *main)
{
    display_pos_endgame_menu(main);
    while (main->menus[1].is_active == sfTrue) {
        while (sfRenderWindow_pollEvent(main->global->window,
        &main->menus[1].menu_events)) {
            analyse_pos_endgame_events(main);
        }
    }
}