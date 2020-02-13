/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** take cmd
*/

#include "../../include/server.h"

int take_error_handling(int fd, char **cmd, int nbt)
{
    if (ltab(cmd) != 2 || nbt == -2) {
        dprintf(fd, "ko\n");
        ftab(cmd);
        return (-1);
    }
    return (0);
}

current_t *print_ko(current_t *t, int fd, char **cmd)
{
    dprintf(fd, "ko\n");
    ftab(cmd);
    return (t);
}

current_t *take(current_t *t, lst_t *target, char **cmd)
{
    player_t *p;
    clock_t cl;
    int e = -1;

    if (take_error_handling(target->fd, cmd, target->nb_team) == -1)
        return (t);
    cl = clock();
    while ((clock() - cl)/CLOCKS_PER_SEC < (7 / t->ser._freq));
    p = get_player_byfd(t->teams[target->nb_team].players, target->fd);
    e = get_inv_byn(cmd[1]);
    if (e == -1 || t->map.tiles[p->x][p->y].inv.objects[e].nb == 0)
        return (print_ko(t, target->fd, cmd));
    t->map.tiles[p->x][p->y].inv.objects[e].nb -= 1;
    p->inv.objects[e].nb += 1;
    dprintf(target->fd, "ok\n");
    p->st = 1;
    pgt(t, target, e);
    ftab(cmd);
    return (t);
}