/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** bct cmd
*/

#include "../../include/server.h"

int mct_error_handling(int fd, char **cmd, int nbt)
{
    if (ltab(cmd) != 1 || nbt != -2) {
        dprintf(fd, "suc\n");
        ftab(cmd);
        return (-1);
    }
    return (0);
}

current_t *mct(current_t *t, lst_t *target, char **cmd)
{

    if (mct_error_handling(target->fd, cmd, target->nb_team) == -1)
        return (t);
    for (int i = 0; i < t->map.x; i++) {
        for (int j = 0; j < t->map.y; j++)
            display_inv(target->fd, t->map.tiles[i][j].inv, i, j);
    }
    ftab(cmd);
    return (t);
}