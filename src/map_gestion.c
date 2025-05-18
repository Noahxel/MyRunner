/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** map_gestion
*/

#include "../include/my_runner.h"

int map_gestion(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (84);
   return (0);
}

void spike_setup(main_t *main)
{
    int spike_id = 0;

    for (int i = 0; i <= my_strlen(main->global->str_map); i++) {
        if (main->global->str_map[i] == '3') {
            main->s_g->spikes_nbr++;
        }
    }
    main->spikes = malloc(sizeof(spikes_t) * main->s_g->spikes_nbr);
    for (int i = 0; main->global->str_map[i] != '1'; i++) {
        if (main->global->str_map[i] == '3') {
            main->spikes[spike_id] =
            set_spikes(main->s_g->tmp_x, main->s_g->tmp_y);
            spike_id++;
        }
        if (main->global->str_map[i] == '\n') {
            main->s_g->tmp_x = 0;
            main->s_g->tmp_y += 100;
        } else
            main->s_g->tmp_x += 200;
    }
}

void block_setup(main_t *main)
{
    int bloc_id = 0;

    for (int i = 0; i <= my_strlen(main->global->str_map); i++) {
        if (main->global->str_map[i] == '2') {
            main->b_g->bloc_nbr++;
        }
    }
    main->blocs = malloc(sizeof(blocs_t) * main->b_g->bloc_nbr);
    for (int i = 0; main->global->str_map[i] != '1'; i++) {
        if (main->global->str_map[i] == '2') {
            main->blocs[bloc_id] =
            set_bloc(main->b_g->tmp_x, main->b_g->tmp_y);
            bloc_id++;
        }
        if (main->global->str_map[i] == '\n') {
            main->b_g->tmp_x = 0;
            main->b_g->tmp_y += 100;
        } else
            main->b_g->tmp_x += 200;
    }
}

void map_len_calc(main_t *main)
{
    for (int i = 0; main->global->str_map[i] != '\0'; i++) {
        if (main->global->str_map[i] == '1')
            main->global->len_map++;
    }
    main->global->len_map /= 2;
    main->global->win_point = main->global->len_map * 200;
}

void obstacles_setup(main_t *main)
{
    block_setup(main);
    spike_setup(main);
    map_len_calc(main);
}
