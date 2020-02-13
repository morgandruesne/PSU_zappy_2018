/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** pnw send
*/

#include "../../include/server.h"

current_t *pnw(current_t *t, lst_t *target)
{
    player_t *p = NULL;

    p = get_player_byfd(t->teams[target->nb_team].players, target->fd);
    if (t->ser._graphfd != -1 && p != NULL) {
        dprintf(t->ser._graphfd, "pnw %d %d %d %c %d %s\n", p->nb, p->x, p->y,
        get_player_rby(p), p->level, t->teams[target->nb_team].name);
    }
    return (t);
}