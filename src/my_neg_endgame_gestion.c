/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** my_endgame_gestion
*/

#include "../include/my_runner.h"

menu_t set_negative_ending3(menu_t neg_end)
{
    sfSprite_setTexture(neg_end.menu_sprite, neg_end.menu_text, sfFalse);
    sfSprite_setTexture(neg_end.button2_sprite, neg_end.button2_text, sfFalse);
    sfSprite_setTexture(neg_end.menu_back_sprite, neg_end.menu_back_text, sfFalse);
    sfSprite_setPosition(neg_end.menu_sprite, neg_end.menu_original_pos);
    sfSprite_setPosition(neg_end.button2_sprite, neg_end.button2_original_pos);
    sfSprite_setScale(neg_end.menu_sprite, neg_end.menu_resize);
    sfSprite_setScale(neg_end.button2_sprite, neg_end.button2_resize);
    return (neg_end);
}

menu_t set_negative_ending2(menu_t neg_end)
{
    sfIntRect play_rect = {0, 0, 384, 316};
    sfIntRect neg_end_rect = {0, 0, 487, 68};
    sfIntRect neg_end_back_rect = {0, 0, 1920, 1080};

    neg_end.is_active = sfTrue;
    neg_end.button2_text = sfTexture_createFromFile("my_png/quit.png",
    &play_rect);
    neg_end.menu_text = sfTexture_createFromFile("my_png/you_died.png",
    &neg_end_rect);
    sfSprite_setTextureRect(neg_end.menu_sprite, neg_end_rect);
    sfSprite_setTextureRect(neg_end.button2_sprite, play_rect);
    sfSprite_setTextureRect(neg_end.menu_back_sprite, neg_end_back_rect);
    return (set_negative_ending3(neg_end));
}

menu_t set_negative_ending(void)
{
    menu_t neg_end;
    sfVector2f quit_btn_pos = {950, 600};
    sfVector2f quit_resize = {1, 1};
    sfVector2f neg_end_pos = {650, 300};
    sfVector2f resize_neg_end = {1, 1};

    neg_end.button2_sprite = sfSprite_create();
    neg_end.menu_sprite = sfSprite_create();
    neg_end.menu_back_sprite = sfSprite_create();
    neg_end.menu_name = "neg_end menu";
    neg_end.menu_original_pos = neg_end_pos;
    neg_end.menu_resize = resize_neg_end;
    neg_end.button2_original_pos = quit_btn_pos;
    neg_end.button2_resize = quit_resize;
    return (set_negative_ending2(neg_end));
}

void analyse_neg_endgame_events(main_t *main)
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
        display_neg_endgame_menu(main);
    if (main->menus[1].menu_events.type == sfEvtClosed)
        sfRenderWindow_close(main->global->window);
}

void negative_ending_gestion(main_t *main)
{
    display_neg_endgame_menu(main);
    while (main->menus[1].is_active == sfTrue) {
        while (sfRenderWindow_pollEvent(main->global->window,
        &main->menus[1].menu_events)) {
            analyse_neg_endgame_events(main);
        }
    }
}