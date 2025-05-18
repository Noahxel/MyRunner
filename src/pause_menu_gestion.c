/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** pause_menu_gestion
*/

#include "../include/my_runner.h"

menu_t set_pause_menu3(menu_t pause)
{
    sfSprite_setTexture(pause.menu_sprite, pause.menu_text, sfFalse);
    sfSprite_setTexture(pause.button1_sprite, pause.button1_text, sfFalse);
    sfSprite_setTexture(pause.button2_sprite, pause.button2_text, sfFalse);
    sfSprite_setTexture(pause.menu_back_sprite, pause.menu_back_text, sfFalse);
    sfSprite_setPosition(pause.menu_sprite, pause.menu_original_pos);
    sfSprite_setPosition(pause.button1_sprite, pause.button1_original_pos);
    sfSprite_setPosition(pause.button2_sprite, pause.button2_original_pos);
    sfSprite_setScale(pause.menu_sprite, pause.menu_resize);
    sfSprite_setScale(pause.button1_sprite, pause.button1_resize);
    sfSprite_setScale(pause.button2_sprite, pause.button2_resize);
    return (pause);
}

menu_t set_pause_menu2(menu_t pause)
{
    sfIntRect play_rect = {0, 0, 384, 316};
    sfIntRect pause_rect = {0, 0, 487, 68};
    sfIntRect pause_back_rect = {0, 0, 1920, 1080};

    pause.is_active = sfTrue;
    pause.button2_text = sfTexture_createFromFile("my_png/quit.png",
    &play_rect);
    pause.button1_text = sfTexture_createFromFile("my_png/resume.png",
    &play_rect);
    pause.menu_text = sfTexture_createFromFile("my_png/pause_txt.png",
    &pause_rect);
    sfSprite_setTextureRect(pause.menu_sprite, pause_rect);
    sfSprite_setTextureRect(pause.button1_sprite, play_rect);
    sfSprite_setTextureRect(pause.button2_sprite, play_rect);
    sfSprite_setTextureRect(pause.menu_back_sprite, pause_back_rect);
    return (set_pause_menu3(pause));
}

menu_t set_pause_menu(void)
{
    menu_t pause;
    sfVector2f play_resize = {1, 1};
    sfVector2f play_btn_pos = {450, 600};
    sfVector2f quit_btn_pos = {950, 600};
    sfVector2f quit_resize = {1, 1};
    sfVector2f pause_pos = {650, 300};
    sfVector2f resize_pause = {1, 1};

    pause.button2_sprite = sfSprite_create();
    pause.button1_sprite = sfSprite_create();
    pause.menu_sprite = sfSprite_create();
    pause.menu_back_sprite = sfSprite_create();
    pause.menu_name = "Pause menu";
    pause.button1_original_pos = play_btn_pos;
    pause.button1_resize = play_resize;
    pause.menu_original_pos = pause_pos;
    pause.menu_resize = resize_pause;
    pause.button2_original_pos = quit_btn_pos;
    pause.button2_resize = quit_resize;
    return (set_pause_menu2(pause));
}

void analyse_pause_menu_events(main_t *main)
{
    sfVector2i coo;

    coo = sfMouse_getPositionRenderWindow(main->global->window);
    if (((coo.x >= main->menus[1].button1_original_pos.x)
    && (coo.x <= (main->menus[1].button1_original_pos.x + 383)))
    && ((coo.y >= main->menus[1].button1_original_pos.y)
    && (coo.y <= (main->menus[1].button1_original_pos.y + 314)))) {
        if (main->menus[1].menu_events.type == sfEvtMouseButtonPressed)
            main->menus[1].is_active = sfFalse;
    } else if (((coo.x >= main->menus[1].button1_original_pos.x)
    && (coo.x <= (main->menus[1].button2_original_pos.x + 384)))
    && ((coo.y >= main->menus[1].button2_original_pos.y)
    && (coo.y <= (main->menus[1].button2_original_pos.y + 316)))) {
        if (main->menus[1].menu_events.type == sfEvtMouseButtonPressed)
            sfRenderWindow_close(main->global->window);
    } else
        display_pause_menu(main);
    if (main->menus[1].menu_events.type == sfEvtClosed)
        sfRenderWindow_close(main->global->window);
}

void pause_menu_gestion(main_t *main)
{
    //sfVector2i coo;
    main->menus[1].is_active = sfTrue;
    display_pause_menu(main);
    while (main->menus[1].is_active == sfTrue) {
        while (sfRenderWindow_pollEvent(main->global->window,
        &main->menus[1].menu_events)) {
            //coo = sfMouse_getPositionRenderWindow(main->global->window);
            //sfSprite_setPosition(main->global->cursor_sprite,
            //(sfVector2f){coo.x - 28.75, coo.y - 27.75});
            analyse_pause_menu_events(main);
        }
    }
}