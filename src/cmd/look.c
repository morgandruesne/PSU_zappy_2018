/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** look cmd
*/

#include "../../include/server.h"
#include <math.h>

int look_error_handling(int fd, char **cmd, int nbt, int freq)
{
    clock_t cl;

    if (ltab(cmd) != 1 || nbt == -2) {
        dprintf(fd, "ko\n");
        ftab(cmd);
        return (-1);
    }
    cl = clock();
    while ((clock() - cl)/CLOCKS_PER_SEC < (7 / freq));
    return (0);
}

char *add_case(char *s, double x, double y, map_t *m)
{
    int nx = (int)(x + m->x) % 10;
    int ny = (int)(y + m->y) % 10;

    for (int i = 0; i < m->tiles[nx][ny].nb_players; i++) {
        if (s != NULL)
            s = mstrconcat(s, " ", 1);
        s = mstrconcat(s, "player", 1);
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < m->tiles[nx][ny].inv.objects[i].nb; j++) {
            s = mstrconcat(s, " ", 1);
            s = mstrconcat(s, m->tiles[nx][ny].inv.objects[i].name, 1);
        }
    }
    return (s);
}

current_t *look(current_t *t, lst_t *tar, char **cmd)
{
    player_t *p = NULL;
    char *str = strdup("[");

    if (look_error_handling(tar->fd, cmd, tar->nb_team, t->ser._freq) == -1)
        return (t);
    p = get_player_byfd(t->teams[tar->nb_team].players, tar->fd);
    str = add_case(str, p->x, p->y, &t->map);
    for (int i = 1, balise = 1; i <= p->level; i++, balise++) {
        for (int j = 0 - balise; j <= 0 + balise; j++) {
            str = mstrconcat(str, ",", 1);
            str = add_case(str, arx(j, i, p->r) + p->x, ary(j, i, p->r) +
            p->y, &t->map);
        }
    }
    str = mstrconcat(str, "]", 1);
    dprintf(tar->fd, "%s\n", str);
    p->st = 1;
    free(str);
    ftab(cmd);
    return (t);
}