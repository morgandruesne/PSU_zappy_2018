/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** ppo cmd
*/

#include "../../include/server.h"

int ppo_error_handling(int fd, char **cmd, int nbt)
{
    if (ltab(cmd) != 2 || nbt != -2) {
        dprintf(fd, "suc\n");
        ftab(cmd);
        return (-1);
    }
    return (0);
}

player_t *ppo_forward(current_t *t, player_t *p)
{
    if (t->ser._graphfd != -1) {
        dprintf(t->ser._graphfd, "ppo %d %d %d %c\n", p->nb, p->x, p->y,
        get_player_rby(p));
    }
    p->st = 1;
    return (p);
}

current_t *ppo(current_t *t, lst_t *target, char **cmd)
{
    player_t *p = NULL;

    if (ppo_error_handling(target->fd, cmd, target->nb_team) == -1)
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
    dprintf(target->fd, "ppo %d %d %d %c\n", p->nb, p->x, p->y,
    get_player_rby(p));
    ftab(cmd);
    return (t);
}