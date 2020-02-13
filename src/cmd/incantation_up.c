/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** incantation cmd
*/

#include "../../include/server.h"

current_t *up_player_concern_by_team(current_t *t, player_t *li, player_t *p)
{
    player_t *tmp = NULL;

    tmp = li;
    while (tmp != NULL) {
        if (tmp != p && tmp->x == p->x && tmp->y == p->y &&
        tmp->level < p->level) {
            tmp->level = p->level;
            tmp->st = 1;
            dprintf(tmp->master, "Current level: %d\n", tmp->level);
        }
        tmp = tmp->n;
    }
    return (t);
}

current_t *up_all_player_concern(current_t *t, player_t *p)
{
    for (int i = 0; i < t->nbts; i++)
        t = up_player_concern_by_team(t, t->teams[i].players, p);
    p->st = 1;
    return (t);
}