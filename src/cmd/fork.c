/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** fork cmd
*/

#include "../../include/server.h"

int fork_error_handling(int fd, char **cmd, int nbt)
{
    if (ltab(cmd) != 1 || nbt == -2) {
        dprintf(fd, "ko\n");
        ftab(cmd);
        return (-1);
    }
    return (0);
}

int get_team_nbcf(team_t *t)
{
    int e = 0;

    for (int i = 0; i < t->nb; i++) {
        if (t->clients[i] == -1)
            e++;
    }
    return (e);
}

current_t *print_fork_ko(current_t *t, int fd, char **cmd)
{
    dprintf(fd, "ko\n");
    ftab(cmd);
    return (t);
}

current_t *forkp(current_t *t, lst_t *tar, char **cmd)
{
    clock_t cl;
    player_t *player;
    int e = 0;
    egg_t *egg;

    if (fork_error_handling(tar->fd, cmd, tar->nb_team) == -1)
        return (t);
    cl = clock();
    while ((clock() - cl)/CLOCKS_PER_SEC < (42 / t->ser._freq));
    player = get_player_byfd(t->teams[tar->nb_team].players, tar->fd);
    if ((e = get_team_nbcf(&t->teams[tar->nb_team])) == 0)
        return (print_fork_ko(t, tar->fd, cmd));
    t->map.eggs = push_egg(t->map.eggs, (egg = create_egg(tar->nb_team)));
    egg->x = player->x;
    egg->y = player->y;
    t = enw(t, tar, egg);
    dprintf(tar->fd, "ok\n");
    ftab(cmd);
    return (t);
}