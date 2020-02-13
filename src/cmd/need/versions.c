/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** broadcast cmd
*/

#include "../../../include/server.h"

int version_one(player_t *un, player_t *deux, map_t *m)
{
    (void) m;
    return ((abs(un->x - deux->x) * abs(un->x - deux->x)) +
    (abs(un->y - deux->y) * abs(un->y - deux->y)));
}

int version_two(player_t *un, player_t *deux, map_t *m)
{
    return ((abs(un->x - (deux->x - m->x)) * abs(un->x - deux->x)) +
    (abs(un->y - deux->y) * abs(un->y - deux->y)));
}

int version_three(player_t *un, player_t *deux, map_t *m)
{
    return ((abs(un->x - deux->x) * abs(un->x - deux->x)) +
    (abs(un->y - deux->y) * abs(un->y - (deux->y - m->y))));
}

int version_four(player_t *un, player_t *deux, map_t *m)
{
    return ((abs(un->x - (deux->x - m->x)) * abs(un->x - deux->x)) +
    (abs(un->y - deux->y) * abs(un->y - (deux->y - m->y))));
}