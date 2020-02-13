/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** byeserver cmd
*/

#include "../../include/server.h"

int byeserver_error_handling(int fd, char **cmd, int nbt)
{
    if (ltab(cmd) != 1 || nbt != -2) {
        dprintf(fd, "suc\n");
        ftab(cmd);
        return (-1);
    }
    return (0);
}

current_t *byeserver(current_t *t, lst_t *target, char **cmd)
{
    if (byeserver_error_handling(target->fd, cmd, target->nb_team) == -1)
        return (t);
    dprintf(target->fd, "BYE\n");
    close(target->fd);
    t->ser._graphfd = -1;
    t->ser._fds = delete_lst_node(t->ser._fds, target);
    ftab(cmd);
    return (t);
}