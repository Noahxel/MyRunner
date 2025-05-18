/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** my_runner
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/System/Export.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef MY_RUNNER_H_
    #define MY_RUNNER_H_

typedef struct bloc_gestion_s {
    int bloc_nbr;
    int bloc_found;
    int tmp_x;
    int tmp_y;
    sfBool colision;
    sfBool end_bloc;
} bloc_gestion_t;

typedef struct spikes_gestion_s {
    int spikes_nbr;
    int spikes_found;
    int tmp_x;
    int tmp_y;
    sfBool colision;
} spikes_gestion_t;

typedef struct paralax_s {
    char *paralax_name;
    sfTexture *text;
    sfSprite *sprite;
    sfClock *clock;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f resize;
} paralax_t;

typedef struct spikes_s {
    sfTexture *text;
    sfSprite *sprite;
    sfClock *clock;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f resize;
} spikes_t;

typedef struct blocs_s {
    sfTexture *text;
    sfSprite *sprite;
    sfClock *clock;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f resize;
} blocs_t;

typedef struct charac_s {
    char *char_name;
    sfTexture *text;
    sfSprite *sprite;
    sfClock *clock;
    sfIntRect rect;
    sfBool is_active;
    sfVector2f pos;
    sfVector2f resize;
    int cooldown_rect;
} charac_t;

typedef struct menu_s {
    char *menu_name;
    sfTexture *menu_text;
    sfSprite *menu_sprite;
    sfVector2f menu_original_pos;
    sfTexture *button1_text;
    sfSprite *button1_sprite;
    sfVector2f button1_original_pos;
    sfTexture *button2_text;
    sfSprite *button2_sprite;
    sfVector2f button2_original_pos;
    sfVector2f menu_resize;
    sfVector2f button1_resize;
    sfVector2f button2_resize;
    sfBool is_active;
    sfSprite *menu_back_sprite;
    sfTexture *menu_back_text;
    sfEvent menu_events;
} menu_t;

typedef struct global_s {
    sfEvent event;
    sfRenderWindow *window;
    sfClock *move_cooldown;
    sfClock *event_cooldoxn;
    sfClock *bloc_cooldown;
    sfClock *spikes_cooldown;
    charac_t *actual_char;
    sfBool neg_endgame;
    sfBool pos_endgame;
    int ground_hight;
    char *str_map;
    int len_map;
    int win_point;
} global_t;

typedef struct main_s {
    global_t *global;
    charac_t *charac;
    paralax_t *paralax;
    blocs_t *blocs;
    spikes_t *spikes;
    menu_t *menus;
    bloc_gestion_t *b_g;
    spikes_gestion_t *s_g;
} main_t;

//////////////////// events //////////////////////////////
void manage_mouse_click(sfRenderWindow *window);

void analyse_events(main_t *main);
//////////////////////////////////////////////////////////


////////////////////// move_rects ////////////////////////
void move_ground_rect(main_t *main, int max, int decal);

void move_back_rect(main_t *main, int max, int decal);

void move_char_rect(main_t *main);

void move_crow_rect(main_t *main, int max, int decal);
//////////////////////////////////////////////////////////


////////////////////// display ///////////////////////////
void display_sprite(main_t *main, sfSprite *sprite);

void manage_paralax_display(main_t *main, charac_t my_char);

void manage_char_display(main_t *main, charac_t my_char);
//////////////////////////////////////////////////////////


//////////////////////// setup ///////////////////////////
main_t *my_setup(void);

paralax_t set_back(void);

paralax_t set_ground(void);

paralax_t set_crow(void);

charac_t set_char(void);

charac_t set_jump(void);

charac_t set_roll(void);

global_t *set_global(main_t *main);

bloc_gestion_t *set_bloc_struct(void);

blocs_t set_bloc(int x, int y);

spikes_gestion_t *set_spikes_struct(void);

spikes_t set_spikes(int x, int y);

menu_t set_main_menu(void);

menu_t set_pause_menu(void);

menu_t set_negative_ending(void);
//////////////////////////////////////////////////////////


///////////////////// Map Gestion ////////////////////////

void spike_setup(main_t *main);

void block_setup(main_t *main);

char *extract_str(char const *filepath);

int **my_str_to_arr_int(char *str, int arraylen, main_t *main);

int my_put_arr_int(int **arr);

int map_gestion(char *filepath);

void check_blocs_colision(main_t *main);

//////////////////////////////////////////////////////////


////////////////////////// other /////////////////////////
void my_runner(main_t *main);

void move_elems(main_t *main);

void move_all_chars(main_t * main, int x_value, int y_value);

void move_all_chars_to(main_t * main, int x_value, int y_value);

void main_menu_gestion(main_t *main);

void pause_menu_gestion(main_t *main);

void display_pause_menu(main_t *main);

void display_main_menu(main_t *main);

void display_neg_endgame_menu(main_t *main);

void display_pos_endgame_menu(main_t *main);

void negative_ending_gestion(main_t *main);

void positive_ending_gestion(main_t *main);

void obstacles_setup(main_t *main);

void my_endgame_gestion(main_t *main);

menu_t set_positive_ending(void);

#endif /* !MY_RUNNER_H_ */
