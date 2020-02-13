/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** main
*/

#include "../include/server.h"

current_t *server_listening(current_t *t, struct timeval *tv)
{
    fd_set fdread;

    FD_ZERO(&fdread);
    FD_SET(t->ser._socket, &fdread);
    fd_set_clients(t->ser._fds, &fdread);
    if (select(FD_SETSIZE, &fdread, NULL, NULL, tv) < 0)
        return (t);
    for (int i = FD_SETSIZE - 1; i >= 0; i--) {
        t = check_fd(t, i, &fdread);
    }
    return (t);
}

current_t *active_player_egg(current_t *t, egg_t *egg)
{
    player_t *p = NULL;

    if (egg->nbc != -1) {
        p = get_player_byfd(t->teams[egg->nb_team].players, egg->nbc);
        p->st = 1;
        dprintf(egg->nbc, "%d\n%d %d\n", t->teams[egg->nb_team].nb -
        (get_team_nbp(t->teams[egg->nb_team].clients,
        t->teams[egg->nb_team].nb)), egg->x, egg->y);
        t->map.tiles[egg->x][egg->y].nb_players += 1;
        t = eht(t, egg);
        t = pnw(t, get_lst_byfd(t->ser._fds, egg->nbc));
    }
    return (t);
}

current_t *check_egg(current_t *t, clock_t *clegg)
{
    egg_t *tmp = NULL;
    egg_t *tp = NULL;

    tmp = t->map.eggs;
    while (tmp != NULL) {
        tmp->time -= 1;
        tmp = tmp->n;
    }
    tmp = t->map.eggs;
    while (tmp != NULL) {
        if (tmp->time == 0) {
            tp = tmp;
            tmp = tmp->n;
            t = active_player_egg(t, tp);
            t->map.eggs = delete_egg_node(t->map.eggs, tp);
        } else
            tmp = tmp->n;
    }
    (*clegg) = clock();
    return (t);
}

int process(current_t *t)
{
    int lck = 0;
    clock_t cl = clock();
    clock_t clgi = clock();
    clock_t clegg = clock();
    int e = 0;
    struct timeval tv = create_tv();

    while (lck == 0 && e == 0) {
        if ((clock() - cl)/CLOCKS_PER_SEC >= (126 / t->ser._freq)) {
            t = server_cycle(t);
            e = check_end(t);
            cl = clock();
        }
        if ((clock() - clgi)/CLOCKS_PER_SEC >= (10 / t->ser._freq))
            generate_item(t->ser._graphfd, &t->map, &clgi);
        if ((clock() - clegg)/CLOCKS_PER_SEC >= (100 / t->ser._freq))
            t = check_egg(t, &clegg);
        t = server_listening(t, &tv);
    }
    return (0);
}

int main(int ac, char **av)
{
    int error = 0;
    current_t *t = NULL;

    t = create_current();
    if ((error = error_handling(ac, av, &t)) != 0)
        return ((error == -1) ? 84 : 0);
    if (check_current(t) == 84)
        return (84);
    if (t->map.x != 10 || t->map.y != 10)
        t->map = create_map(t->map.x, t->map.y);
    if (t == NULL)
        return (84);
    if (initiation_server(&t->ser) == -1)
        return (return_p(t, "server error : initiation", 84, 2));
    process(t);
    return (return_p(t, "zappy server : down", 0, 2));
}