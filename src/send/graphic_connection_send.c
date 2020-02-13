/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** graphic connection send
*/

#include "../../include/server.h"

current_t *send_player_by_team(current_t *t, player_t *li, char *str)
{
    player_t *tmp = NULL;

    tmp = li;
    while (tmp != NULL) {
        dprintf(t->ser._graphfd, "pnw %d %d %d %c %d %s\n", tmp->nb, tmp->x,
        tmp->y, get_player_rby(tmp), tmp->level, str);
        tmp = tmp->n;
    }
    return (t);
}

current_t *send_all_player(current_t *t)
{
    for (int i = 0; i < t->nbts; i++)
        t = send_player_by_team(t, t->teams[i].players,
        t->teams[i].name);
    return (t);
}

current_t *send_info_to_graphic_connection(current_t *t, lst_t *target)
{
    t = msz(t, target, my_split("msz", ' '));
    t = mct(t, target, my_split("mct", ' '));
    t = send_all_player(t);
    return (t);
}