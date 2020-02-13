/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** pin cmd
*/

#include "../../include/server.h"

int pin_error_handling(int fd, char **cmd, int nbt)
{
    if (ltab(cmd) != 2 || nbt != -2) {
        dprintf(fd, "suc\n");
        ftab(cmd);
        return (-1);
    }
    return (0);
}

current_t *pin(current_t *t, lst_t *target, char **cmd)
{
    player_t *p;

    if (pin_error_handling(target->fd, cmd, target->nb_team) == -1)
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
    dprintf(target->fd, "pin %d %d %d %d %d %d %d %d %d\n", p->x, p->y,
    p->inv.objects[0].nb, p->inv.objects[1].nb, p->inv.objects[2].nb,
    p->inv.objects[3].nb, p->inv.objects[4].nb, p->inv.objects[5].nb,
    p->inv.objects[6].nb);
    ftab(cmd);
    return (t);
}