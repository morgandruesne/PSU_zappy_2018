/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** eject cmd
*/

#include "../../include/server.h"

int eject_error_handling(int fd, char **cmd, int nbt)
{
    if (ltab(cmd) != 1 || nbt == -2) {
        dprintf(fd, "ko\n");
        ftab(cmd);
        return (-1);
    }
    return (0);
}

current_t *move_player_concern_by_team(current_t *t, player_t *li, player_t *p)
{
    player_t *tmp = NULL;
    int move = 0;

    tmp = li;
    move = know_move(p->r);
    while (tmp != NULL) {
        if (tmp != p && tmp->x == p->x && tmp->y == p->y) {
            t->map.tiles[p->x][p->y].nb_players -= 1;
            tmp->x += (p->r == 30 || p->r == 90) ? move : 0;
            tmp->y += (p->r == 0 || p->r == 60) ? move : 0;
            tmp->x = ajust_x(tmp->x, t->map.x);
            tmp->y = ajust_y(tmp->y, t->map.y);
            t->map.tiles[tmp->x][tmp->y].nb_players += 1;
            dprintf(tmp->master, "eject: %c\n", get_player_rby(p));
        }
        tmp = tmp->n;
    }
    return (t);
}

current_t *move_all_player_concern(current_t *t, player_t *p)
{
    for (int i = 0; i < t->nbts; i++)
        t = move_player_concern_by_team(t, t->teams[i].players, p);
    return (t);
}

current_t *eject(current_t *t, lst_t *target, char **cmd)
{
    player_t *p;
    clock_t cl;

    if (eject_error_handling(target->fd, cmd, target->nb_team) == -1)
        return (t);
    cl = clock();
    while ((clock() - cl)/CLOCKS_PER_SEC < (7 / t->ser._freq));
    p = get_player_byfd(t->teams[target->nb_team].players, target->fd);
    t = move_all_player_concern(t, p);
    dprintf(target->fd, "ok\n");
    if (t->ser._graphfd != -1)
        dprintf(t->ser._graphfd, "pex %d\n", p->nb);
    p->st = 1;
    ftab(cmd);
    return (t);
}