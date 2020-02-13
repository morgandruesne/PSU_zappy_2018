/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** incantation cmd
*/

#include "../../include/server.h"

int incantation_error_handling(int fd, char **cmd, int nbt)
{
    if (ltab(cmd) != 1 || nbt == -2) {
        dprintf(fd, "ko\n");
        ftab(cmd);
        return (-1);
    }
    return (0);
}

inv_t *get_need(int lr, inv_t *n)
{
    n->objects[0].nb = get_player(lr);
    n->objects[1].nb = get_linemate(lr);
    n->objects[2].nb = get_deraumere(lr);
    n->objects[3].nb = get_sibur(lr);
    n->objects[4].nb = get_mendiane(lr);
    n->objects[5].nb = get_phiras(lr);
    n->objects[6].nb = get_thystame(lr);
    return (n);
}

int check_incantation_condition(int lr, map_t *m, player_t *p, inv_t *n)
{
    n = get_need(lr, n);
    if (p->level == 8)
        return (-1);
    if (m->tiles[p->x][p->y].nb_players < n->objects[0].nb)
        return (-1);
    for (int i = 1; i < 7; i++) {
        if (m->tiles[p->x][p->y].inv.objects[i].nb < n->objects[i].nb)
            return (-1);
    }
    return (0);
}

current_t *supress_need(current_t *t, player_t *p, inv_t *n)
{
    for (int i = 1; i < 7; i++) {
        t->map.tiles[p->x][p->y].inv.objects[i].nb -= n->objects[i].nb;
    }
    free(n->objects);
    p->level += 1;
    p->st = 1;
    dprintf(p->master, "Current level: %d\n", p->level);
    if (p->level != 2)
        t = up_all_player_concern(t, p);
    return (t);
}

current_t *incantation(current_t *t, lst_t *target, char **cmd)
{
    clock_t cl;
    player_t *p;
    inv_t need = create_inv_int(0);

    if (incantation_error_handling(target->fd, cmd, target->nb_team) == -1)
        return (t);
    p = get_player_byfd(t->teams[target->nb_team].players, target->fd);
    if (check_incantation_condition(p->level + 1, &t->map, p, &need) == -1)
        return (error_incd(t, target->fd, cmd, &need));
    cl = clock();
    dprintf(target->fd, "Elevation underway\n");
    pic(t, p);
    while ((clock() - cl)/CLOCKS_PER_SEC < (300 / t->ser._freq));
    if (check_incantation_condition(p->level + 1, &t->map, p, &need) == -1) {
        pie(t, p, 1);
        return (error_inc(t, target->fd, cmd, &need));
    }
    t = supress_need(t, p, &need);
    pie(t, p, 0);
    ftab(cmd);
    return (t);
}