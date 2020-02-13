/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** msz cmd
*/

#include "../../include/server.h"

int msz_error_handling(int fd, char **cmd, int nbt)
{
    if (ltab(cmd) != 1 || nbt != -2) {
        dprintf(fd, "suc\n");
        ftab(cmd);
        return (-1);
    }
    return (0);
}

current_t *msz(current_t *t, lst_t *target, char **cmd)
{
    if (msz_error_handling(target->fd, cmd, target->nb_team) == -1)
        return (t);
    dprintf(target->fd, "msz %d %d\n", t->map.x, t->map.y);
    ftab(cmd);
    return (t);
}