/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** try push team
*/

#include "../../include/server.h"

egg_t *get_egg_byteam(egg_t *list, int nb)
{
    egg_t *t;

    if (list == NULL)
        return (NULL);
    t = list;
    while (t != NULL) {
        if (t->nb_team == nb && t->nbc == -1)
            return (t);
        t = t->n;
    }
    return (NULL);
}

current_t *push_team(current_t *t, lst_t *target, int i, int e)
{
    player_t *p = NULL;
    egg_t *f = NULL;

    t->teams[i].clients = add_client_toteam(t->teams[i].clients,
    target->fd, t->teams[i].nb);
    p = create_player(target->fd);
    if ((f = get_egg_byteam(t->map.eggs, i)) != NULL) {
        p->x = f->x;
        p->y = f->y;
        p->st = 2;
        f->nbc = target->fd;
    }
    t->teams[i].players = push_player(t->teams[i].players, p);
    if (p->st != 2) {
        t->map.tiles[0][0].nb_players += 1;
        pnw(t, target);
        dprintf(target->fd, "%d\n%d %d\n", t->teams[i].nb - (e + 1),
        t->map.x, t->map.y);
    }
    return (t);
}

current_t *try_push_team(current_t *t, lst_t *target, char *str)
{
    int i = get_team_byname(t, str);
    int e = 0;

    if (i == -1) {
        dprintf(target->fd, "ko\n");
        printf("failed to add at a team : %d\n", target->fd);
        return (t);
    } else if ((e = get_team_nbp(t->teams[i].clients, t->teams[i].nb))
    == t->teams[i].nb) {
        dprintf(target->fd, "ko\n");
        printf("failed to add at a team : %d\n", target->fd);
        return (t);
    }
    target->nb_team = i;
    t = push_team(t, target, i, e);
    return (t);
}