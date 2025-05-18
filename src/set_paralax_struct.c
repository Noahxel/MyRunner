/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** my_set_struct
*/

#include "../include/my_runner.h"

paralax_t set_back(void)
{
    paralax_t back;
    sfVector2f resize = {0.97, 0.97};
    sfIntRect rect = {0, 0, 2500, 929};
    sfVector2f pos = {0, 0};

    back.paralax_name = "backgound";
    back.rect = rect;
    back.resize = resize;
    back.pos = pos;
    back.clock = sfClock_create();
    back.sprite = sfSprite_create();
    back.text = sfTexture_createFromFile("my_png/background.png", NULL);
    sfSprite_setTexture(back.sprite, back.text, sfFalse);
    sfSprite_setScale(back.sprite, back.resize);
    sfSprite_setPosition(back.sprite, back.pos);
    return (back);
}

paralax_t set_ground(void)
{
    paralax_t ground;
    sfVector2f resize = {0.55, 0.5};
    sfVector2f pos = {0, 890};
    sfIntRect rect = {0, 0, 3830, 730};

    ground.paralax_name = "ground";
    ground.rect = rect;
    ground.resize = resize;
    ground.pos = pos;
    ground.clock = sfClock_create();
    ground.sprite = sfSprite_create();
    ground.text = sfTexture_createFromFile("my_png/ground.png", NULL);
    sfSprite_setPosition(ground.sprite, ground.pos);
    sfSprite_setTexture(ground.sprite, ground.text, sfFalse);
    sfSprite_setScale(ground.sprite, ground.resize);
    return (ground);
}

paralax_t set_crow(void)
{
    paralax_t crow;
    sfIntRect rect = {0, 0, 76, 98};
    sfVector2f pos = {1920, 0};
    sfVector2f resize = {0.8, 0.8};

    srand(time(NULL));
    crow.paralax_name = "crow";
    crow.resize = resize;
    crow.rect = rect;
    crow.pos = pos;
    crow.pos.y += rand() % 250;
    crow.clock = sfClock_create();
    crow.sprite = sfSprite_create();
    crow.text = sfTexture_createFromFile("my_png/crow.png", NULL);
    sfSprite_setPosition(crow.sprite, crow.pos);
    sfSprite_setTexture(crow.sprite, crow.text, sfFalse);
    sfSprite_setTextureRect(crow.sprite, crow.rect);
    sfSprite_setScale(crow.sprite, resize);
    return (crow);
}
