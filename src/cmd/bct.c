/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** bct cmd
*/

#include "../../include/server.h"

int bct_error_handling(int fd, char **cmd, int nbt)
{
    if (ltab(cmd) != 3 || nbt != -2) {
        dprintf(fd, "suc\n");
        ftab(cmd);
        return (-1);
    }
    return (0);
}

current_t *bct(current_t *t, lst_t *target, char **cmd)
{
    int x = 0;
    int y = 0;

    if (bct_error_handling(target->fd, cmd, target->nb_team) == -1)
        return (t);
    x = atoi(cmd[1]);
    y = atoi(cmd[2]);
    if (x >= t->map.x || y >= t->map.y) {
        dprintf(target->fd, "suc\n");
        ftab(cmd);
        return (t);
    }
    display_inv(target->fd, t->map.tiles[x][x].inv, x, y);
    ftab(cmd);
    return (t);
}