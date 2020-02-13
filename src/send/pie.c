/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** pie send
*/

#include "../../include/server.h"

current_t *pie(current_t *t, player_t *p, int r)
{
    if (t->ser._graphfd != -1) {
        if (r == 0)
            dprintf(t->ser._graphfd, "pie %d %d okay\n", p->x, p->y);
        else
            dprintf(t->ser._graphfd, "pie %d %d fail\n", p->x, p->y);
    }
    return (t);
}