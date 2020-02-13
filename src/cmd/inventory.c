/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** inventory cmd
*/

#include "../../include/server.h"

int inventory_error_handling(int fd, char **cmd, int nbt)
{
    if (ltab(cmd) != 1 || nbt == -2) {
        dprintf(fd, "ko\n");
        ftab(cmd);
        return (-1);
    }
    return (0);
}

char *get_inventory(player_t *player)
{
    char *str = NULL;
    char buff[15];

    str = mstrconcat("[", NULL, 4);
    for (int i = 0; i < 7; i++) {
        snprintf(buff, 15, "%d", player->inv.objects[i].nb);
        str = mstrconcat(str, player->inv.objects[i].name, 1);
        str = mstrconcat(str, " ", 1);
        str = mstrconcat(str, buff, 1);
        if (i != 6)
            str = mstrconcat(str, ",", 1);
        else
            str = mstrconcat(str, "]", 1);
    }
    return (str);
}

current_t *inventory(current_t *t, lst_t *target, char **cmd)
{
    clock_t cl;
    player_t *player;
    char *str = NULL;

    if (inventory_error_handling(target->fd, cmd, target->nb_team) == -1)
        return (t);
    cl = clock();
    while ((clock() - cl)/CLOCKS_PER_SEC < (1 / t->ser._freq));
    player = get_player_byfd(t->teams[target->nb_team].players, target->fd);
    str = get_inventory(player);
    dprintf(target->fd, "%s\n", str);
    player->st = 1;
    free(str);
    ftab(cmd);
    return (t);
}