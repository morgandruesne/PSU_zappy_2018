/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** broadcast cmd
*/

#include "../../include/server.h"

int broadcast_error_handling(int fd, char **cmd, int nbt)
{
    if (ltab(cmd) != 2 || nbt == -2) {
        dprintf(fd, "ko\n");
        ftab(cmd);
        return (-1);
    }
    return (0);
}

void doBroadcast(lst_t *list, player_t *p, char *mess, int fd_ref)
{
    lst_t *tmp;
    int e = 0;

    if (list == NULL)
        return;
    tmp = list;
    for (int i = 0; i != p->x; i++) {
        for (int j = 0; j != p->y; j++)
            e++;
    }
    while (tmp != NULL) {
        if (tmp->fd != fd_ref)
            dprintf(tmp->fd, "message %d, %s\n", e, mess);
        tmp = tmp->n;
    }
}

void calc(player_t *un, player_t *deux, int n, char *msg)
{
    int i = 0;

    if (un->x == deux->x && un->y == deux->y) {
        dprintf(deux->master, "message 0, %s\n", msg);
        return;
    }
    if (n == 1)
        i = classic(un, deux);
    if (n == 2)
        i = reverse_x(un, deux);
    if (n == 3)
        i = reverse_y(un, deux);
    if (n == 4)
        i = reverse_xy(un, deux);
    i -= (deux->r == 0) ? 2 : 0;
    i -= (deux->r == 90) ? 4 : 0;
    i -= (deux->r == 60) ? 6 : 0;
    i -= (deux->r == 30) ? 0 : 0;
    if (i < 0)
        i = (i + 9) % 9;
    dprintf(deux->master, "message %d, %s\n", i, msg);
}

current_t *call_players(current_t *t, player_t *m, char *msg)
{
    lst_t *f = NULL;
    player_t *s = NULL;
    int e = 0;
    int n = 1;

    f = t->ser._fds;
    while (f != NULL) {
        s = get_player_byfd(t->teams[f->nb_team].players, f->fd);
        e = version_one(m, s, &t->map);
        if (version_two(m, s, &t->map) < e)
            n = 2;
        if (version_three(m, s, &t->map) < e)
            n = 3;
        if (version_four(m, s, &t->map) < e)
            n = 4;
        calc(m, s, n, msg);
        f = f->n;
    }
    return (t);
}

current_t *broadcast(current_t *t, lst_t *target, char **cmd)
{
    clock_t cl;
    player_t *p;

    if (broadcast_error_handling(target->fd, cmd, target->nb_team) == -1)
        return (t);
    cl = clock();
    p = get_player_byfd(t->teams[target->nb_team].players, target->fd);
    while ((clock() - cl)/CLOCKS_PER_SEC < (7 / t->ser._freq));
    call_players(t, p, cmd[1]);
    dprintf(target->fd, "ok\n");
    pbc(t, target, cmd[1]);
    ftab(cmd);
    return (t);
}