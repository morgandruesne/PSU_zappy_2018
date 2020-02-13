/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** pnw send
*/

#include "../../include/server.h"

current_t *pbc(current_t *t, lst_t *target, char *str)
{
    player_t *p = NULL;

    p = get_player_byfd(t->teams[target->nb_team].players, target->fd);
    if (t->ser._graphfd != -1 && p != NULL)
        dprintf(t->ser._graphfd, "pbc %d %s\n", p->nb, str);
    return (t);
}