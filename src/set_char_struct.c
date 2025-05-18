/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** my_set_struct
*/

#include "../include/my_runner.h"

charac_t set_char(void)
{
    charac_t charac;
    sfVector2f pos = {80, 800};
    sfVector2f resize = {1, 1};
    sfIntRect crect = {0, 0, 86, 102};

    charac.char_name = "Naruto";
    charac.cooldown_rect = 75;
    charac.is_active = sfTrue;
    charac.rect = crect;
    charac.resize = resize;
    charac.pos = pos;
    charac.clock = sfClock_create();
    charac.sprite = sfSprite_create();
    charac.text = sfTexture_createFromFile("my_png/naruto_run.png", NULL);
    sfSprite_setTexture(charac.sprite, charac.text, sfFalse);
    sfSprite_setTextureRect(charac.sprite, charac.rect);
    sfSprite_setScale(charac.sprite, charac.resize);
    sfSprite_setPosition(charac.sprite, charac.pos);
    return (charac);
}

charac_t set_jump(void)
{
    charac_t jump;
    sfIntRect rect = {0, 0, 71, 71};
    sfVector2f pos = {80, 770};
    sfVector2f resize = {1.75, 1.75};

    jump.char_name = "Jumping Naruto";
    jump.cooldown_rect = 175;
    jump.is_active = sfFalse;
    jump.resize = resize;
    jump.rect = rect;
    jump.pos = pos;
    jump.clock = sfClock_create();
    jump.sprite = sfSprite_create();
    jump.text = sfTexture_createFromFile("my_png/Naruto_jump.png", NULL);
    sfSprite_setPosition(jump.sprite, jump.pos);
    sfSprite_setTexture(jump.sprite, jump.text, sfFalse);
    sfSprite_setTextureRect(jump.sprite, jump.rect);
    sfSprite_setScale(jump.sprite, resize);
    return (jump);
}

charac_t set_roll(void)
{
    charac_t roll;
    sfIntRect rect = {0, 0, 75, 75};
    sfVector2f pos = {80, 720};
    sfVector2f resize = {2.4, 2.4};

    roll.char_name = "Rolling Naruto";
    roll.cooldown_rect = 100;
    roll.is_active = sfFalse;
    roll.resize = resize;
    roll.rect = rect;
    roll.pos = pos;
    roll.clock = sfClock_create();
    roll.sprite = sfSprite_create();
    roll.text = sfTexture_createFromFile("my_png/Naruto_roll.png", NULL);
    sfSprite_setPosition(roll.sprite, roll.pos);
    sfSprite_setTexture(roll.sprite, roll.text, sfFalse);
    sfSprite_setTextureRect(roll.sprite, roll.rect);
    sfSprite_setScale(roll.sprite, resize);
    return (roll);
}