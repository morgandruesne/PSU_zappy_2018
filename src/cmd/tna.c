/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** tna cmd
*/

#include "../../include/server.h"

int tna_error_handling(int fd, char **cmd, int nbt)
{
    if (ltab(cmd) != 1 || nbt != -2) {
        dprintf(fd, "suc\n");
        ftab(cmd);
        return (-1);
    }
    return (0);
}

current_t *tna(current_t *t, lst_t *target, char **cmd)
{
    if (tna_error_handling(target->fd, cmd, target->nb_team) == -1)
        return (t);
    for (int i = 0; i < t->nbts; i++)
        dprintf(target->fd, "tna %s\n", t->teams[i].name);
    ftab(cmd);
    return (t);
}