/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** right cmd
*/

#include "../../include/server.h"

int right_error_handling(int fd, char **cmd, int nbt)
{
    if (ltab(cmd) != 1 || nbt == -2) {
        dprintf(fd, "ko\n");
        ftab(cmd);
        return (-1);
    }
    return (0);
}

current_t *right(current_t *t, lst_t *target, char **cmd)
{
    player_t *player;
    clock_t cl;

    if (right_error_handling(target->fd, cmd, target->nb_team) == -1)
        return (t);
    cl = clock();
    while ((clock() - cl)/CLOCKS_PER_SEC < (7 / t->ser._freq));
    player = get_player_byfd(t->teams[target->nb_team].players, target->fd);
    player->r += 30;
    if (player->r == 120)
        player->r = 0;
    dprintf(target->fd, "ok\n");
    printf("%d.r : %d\n", player->master, player->r);
    player->st = 1;
    ftab(cmd);
    return (t);
}