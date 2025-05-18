/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** my_menu_setup
*/

#include "../include/my_runner.h"

menu_t set_main_menu3(menu_t menu)
{
    sfSprite_setTexture(menu.menu_sprite, menu.menu_text, sfFalse);
    sfSprite_setTexture(menu.button1_sprite, menu.button1_text, sfFalse);
    sfSprite_setTexture(menu.button2_sprite, menu.button2_text, sfFalse);
    sfSprite_setTexture(menu.menu_back_sprite, menu.menu_back_text, sfFalse);
    sfSprite_setPosition(menu.menu_sprite, menu.menu_original_pos);
    sfSprite_setPosition(menu.button1_sprite, menu.button1_original_pos);
    sfSprite_setPosition(menu.button2_sprite, menu.button2_original_pos);
    sfSprite_setScale(menu.menu_sprite, menu.menu_resize);
    sfSprite_setScale(menu.button1_sprite, menu.button1_resize);
    sfSprite_setScale(menu.button2_sprite, menu.button2_resize);
    return (menu);
}

menu_t set_main_menu2(menu_t menu)
{
    sfIntRect play_rect = {0, 0, 384, 316};
    sfIntRect menu_rect = {0, 0, 487, 68};
    sfIntRect menu_back_rect = {0, 0, 1920, 1080};

    menu.is_active = sfTrue;
    menu.button2_text = sfTexture_createFromFile("my_png/quit.png",
    &play_rect);
    menu.button1_text = sfTexture_createFromFile("my_png/play.png",
    &play_rect);
    menu.menu_text = sfTexture_createFromFile("my_png/konoha_runner.png",
    &menu_rect);
    menu.menu_back_text = sfTexture_createFromFile
    ("my_png/back_main_menu.png", &menu_back_rect);
    sfSprite_setTextureRect(menu.menu_sprite, menu_rect);
    sfSprite_setTextureRect(menu.button1_sprite, play_rect);
    sfSprite_setTextureRect(menu.button2_sprite, play_rect);
    sfSprite_setTextureRect(menu.menu_back_sprite, menu_back_rect);
    return (set_main_menu3(menu));
}

menu_t set_main_menu(void)
{
    menu_t menu;
    sfVector2f play_resize = {1, 1};
    sfVector2f play_btn_pos = {450, 600};
    sfVector2f quit_btn_pos = {950, 600};
    sfVector2f quit_resize = {1, 1};
    sfVector2f menu_pos = {650, 300};
    sfVector2f resize_menu = {1, 1};

    menu.button2_sprite = sfSprite_create();
    menu.button1_sprite = sfSprite_create();
    menu.menu_sprite = sfSprite_create();
    menu.menu_back_sprite = sfSprite_create();
    menu.menu_name = "Main menu";
    menu.button1_original_pos = play_btn_pos;
    menu.button1_resize = play_resize;
    menu.menu_original_pos = menu_pos;
    menu.menu_resize = resize_menu;
    menu.button2_original_pos = quit_btn_pos;
    menu.button2_resize = quit_resize;
    return (set_main_menu2(menu));
}

void analyse_main_menu_events(main_t *main)
{
    sfVector2i coo;

    coo = sfMouse_getPositionRenderWindow(main->global->window);
    if (((coo.x >= main->menus[0].button1_original_pos.x)
    && (coo.x <= (main->menus[0].button1_original_pos.x + 383)))
    && ((coo.y >= main->menus[0].button1_original_pos.y)
    && (coo.y <= (main->menus[0].button1_original_pos.y + 314)))) {
        if (main->menus[0].menu_events.type == sfEvtMouseButtonPressed)
            main->menus[0].is_active = sfFalse;
    } else if (((coo.x >= main->menus[0].button1_original_pos.x)
    && (coo.x <= (main->menus[0].button2_original_pos.x + 384)))
    && ((coo.y >= main->menus[0].button2_original_pos.y)
    && (coo.y <= (main->menus[0].button2_original_pos.y + 316)))) {
        if (main->menus[0].menu_events.type == sfEvtMouseButtonPressed)
            sfRenderWindow_close(main->global->window);
    } else
        display_main_menu(main);
    if (main->menus[0].menu_events.type == sfEvtClosed) {
        sfRenderWindow_close(main->global->window);
        return;
    }
}

void main_menu_gestion(main_t *main)
{
    display_main_menu(main);
    while (sfRenderWindow_pollEvent(main->global->window,
    &main->menus[0].menu_events)) {
        analyse_main_menu_events(main);
    }
}