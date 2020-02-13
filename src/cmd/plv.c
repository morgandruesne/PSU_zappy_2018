/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** plv cmd
*/

#include "../../include/server.h"

int plv_error_handling(int fd, char **cmd, int nbt)
{
    if (ltab(cmd) != 2 || nbt != -2) {
        dprintf(fd, "suc\n");
        ftab(cmd);
        return (-1);
    }
    return (0);
}

current_t *plv(current_t *t, lst_t *target, char **cmd)
{
    player_t *p;

    if (plv_error_handling(target->fd, cmd, target->nb_team) == -1)
        return (t);
    for (int i = 0; i < t->nbts; i++) {
        if ((p = get_player_bynbp(t->teams[i].players,
        atoi(cmd[1]))) != NULL)
            break;
    }
    if (p == NULL) {
        dprintf(target->fd, "suc\n");
        ftab(cmd);
        return (t);
    }
    dprintf(target->fd, "plv %d %d\n", p->nb, p->level);
    ftab(cmd);
    return (t);
}