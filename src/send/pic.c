/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** pic send
*/

#include "../../include/server.h"

char *get_player_concern_by_team(char *str, player_t *li, player_t *p)
{
    player_t *tmp = NULL;
    char buff[10];

    tmp = li;
    while (tmp != NULL) {
        if (tmp != p && tmp->x == p->x && tmp->y == p->y) {
            sprintf(buff, " %d", tmp->nb);
            str = mstrconcat(str, buff, 1);
        }
        tmp = tmp->n;
    }
    return (str);
}

char *get_all_players_concern(char *str, current_t *t, player_t *p)
{
    for (int i = 0; i < t->nbts; i++)
        str = get_player_concern_by_team(str, t->teams[i].players, p);
    return (str);
}

current_t *pic(current_t *t, player_t *target)
{
    char *str = "pic";
    char buff[10];

    if (t->ser._graphfd != -1) {
        sprintf(buff, " %d", target->x);
        str = mstrconcat(str, buff, 3);
        sprintf(buff, " %d", target->y);
        str = mstrconcat(str, buff, 1);
        sprintf(buff, " %d", target->nb);
        str = mstrconcat(str, buff, 1);
        str = get_all_players_concern(str, t, target);
        dprintf(t->ser._graphfd, "%s\n", str);
        free(str);
    }
    return (t);
}