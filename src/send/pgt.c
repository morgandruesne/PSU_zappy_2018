/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** pgt send
*/

#include "../../include/server.h"

current_t *pgt(current_t *t, lst_t *target, int e)
{
    player_t *p;

    p = get_player_byfd(t->teams[target->nb_team].players, target->fd);
    if (t->ser._graphfd != -1 && p != NULL)
        dprintf(t->ser._graphfd, "pgt %d %d\n", p->nb, e);
    return (t);
}