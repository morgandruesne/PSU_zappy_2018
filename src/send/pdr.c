/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** pdr send
*/

#include "../../include/server.h"

current_t *pdr(current_t *t, lst_t *target, int e)
{
    player_t *p = NULL;

    p = get_player_byfd(t->teams[target->nb_team].players, target->fd);
    if (t->ser._graphfd != -1 && p != NULL)
        dprintf(t->ser._graphfd, "pdr %d %d\n", p->nb, e);
    return (t);
}