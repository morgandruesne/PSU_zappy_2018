/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** server cycle
*/

#include "../../include/server.h"

current_t *check_players_cycle(current_t *t, player_t **players)
{
    player_t *player = NULL;
    player_t *tmp = NULL;

    player = *players;
    while (player != NULL) {
        if (player->st == 1)
            player->st = 0;
        else if (player->st != 2)
            player->inv.objects[0].nb -= 1;
        player = player->n;
    }
    player = *players;
    while (player != NULL) {
        if (player->inv.objects[0].nb == -1) {
            tmp = player;
            player = player->n;
            t = death(t, get_lst_byfd(t->ser._fds, tmp->master), NULL);
        } else
            player = player->n;
    }
    return (t);
}

current_t *server_cycle(current_t *t)
{
    for (int i = 0; i < t->nbts; i++)
        t = check_players_cycle(t, &t->teams[i].players);
    return (t);
}