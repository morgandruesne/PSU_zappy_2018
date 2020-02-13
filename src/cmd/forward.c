/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** forward cmd
*/

#include "../../include/server.h"

int forward_error_handling(int fd, char **cmd, int nbt)
{
    if (ltab(cmd) != 1 || nbt == -2) {
        dprintf(fd, "ko\n");
        ftab(cmd);
        return (-1);
    }
    return (0);
}

int know_move(int r)
{
    if (r == 0 || r == 30)
        return (1);
    if (r == 60 || r == 90)
        return (-1);
    return (0);
}

int ajust_x(int x, int sx)
{
    if (x < 0)
        return (sx - 1);
    if (x >= sx)
        return (0);
    return (x);
}

int ajust_y(int y, int sy)
{
    if (y < 0)
        return (sy - 1);
    if (y >= sy)
        return (0);
    return (y);
}

current_t *forward(current_t *t, lst_t *target, char **cmd)
{
    player_t *p;
    clock_t cl;
    int move = 0;

    if (forward_error_handling(target->fd, cmd, target->nb_team) == -1)
        return (t);
    cl = clock();
    while ((clock() - cl)/CLOCKS_PER_SEC < (7 / t->ser._freq));
    p = get_player_byfd(t->teams[target->nb_team].players, target->fd);
    move = know_move(p->r);
    t->map.tiles[p->x][p->y].nb_players -= 1;
    p->x += (p->r == 30 || p->r == 90) ? move : 0;
    p->y += (p->r == 0 || p->r == 60) ? move : 0;
    p->x = ajust_x(p->x, t->map.x);
    p->y = ajust_y(p->y, t->map.y);
    t->map.tiles[p->x][p->y].nb_players += 1;
    dprintf(target->fd, "ok\n");
    p = ppo_forward(t, p);
    ftab(cmd);
    return (t);
}