/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** enw send
*/

#include "../../include/server.h"

current_t *enw(current_t *t, lst_t *tar, egg_t *egg)
{
    player_t *p = NULL;

    p = get_player_byfd(t->teams[tar->nb_team].players, tar->fd);
    if (t->ser._graphfd != -1 && p != NULL)
        dprintf(t->ser._graphfd, "enw %d %d %d %d\n", egg->nb, p->nb,
        p->x, p->y);
    return (t);
}