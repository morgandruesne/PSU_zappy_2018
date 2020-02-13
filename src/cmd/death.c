/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** death cmd
*/

#include "../../include/server.h"

current_t *print_death(current_t *t, int fd)
{
    dprintf(fd, "dead\n");
    close(fd);
    return (t);
}

current_t *death(current_t *t, lst_t *c, char **cmd)
{
    player_t *player;
    int fd = 0;

    (void) cmd;
    player = get_player_byfd(t->teams[c->nb_team].players, c->fd);
    if (t->ser._graphfd != -1)
        dprintf(t->ser._graphfd, "pdi %d\n", player->nb);
    fd = c->fd;
    t->teams[c->nb_team].clients = supr_client_toteam(
    t->teams[c->nb_team].clients, fd, t->teams[c->nb_team].nb);
    t->teams[c->nb_team].players = delete_player_node(
    t->teams[c->nb_team].players, player);
    t->ser._fds = delete_lst_node(t->ser._fds, c);
    return (print_death(t, fd));
}