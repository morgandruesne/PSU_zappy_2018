/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** nbrc cmd
*/

#include "../../include/server.h"

int nbrc_error_handling(int fd, char **cmd, int nbt)
{
    if (ltab(cmd) != 1 || nbt == -2) {
        dprintf(fd, "suc\n");
        ftab(cmd);
        return (-1);
    }
    return (0);
}

current_t *nbrc(current_t *t, lst_t *tar, char **cmd)
{
    int e = 0;
    player_t * p = NULL;

    if (nbrc_error_handling(tar->fd, cmd, tar->nb_team) == -1)
        return (t);
    p = get_player_byfd(t->teams[tar->nb_team].players, tar->fd);
    for (int i = 0; i < t->teams[tar->nb_team].nb; i++) {
        if (t->teams[tar->nb_team].clients[i] == -1)
            e++;
    }
    dprintf(tar->fd, "%d\n", e);
    p->st = 1;
    ftab(cmd);
    return (t);
}