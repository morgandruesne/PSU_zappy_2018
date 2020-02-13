/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** check_end game
*/

#include "../../include/server.h"

int check_players_level(player_t *players)
{
    player_t *player = NULL;

    player = players;
    while (player != NULL) {
        if (player->level == 8)
            return (1);
        player = player->n;
    }
    return (0);
}

int says_players_result(player_t *players, int i)
{
    player_t *player = NULL;

    player = players;
    while (player != NULL) {
        if (i == 1)
            dprintf(player->master, "winner\n");
        else
            dprintf(player->master, "loser\n");
        player = player->n;
    }
    return (0);
}

int check_end(current_t *t)
{
    int r = 0;

    for (int i = 0; i < t->nbts; i++) {
        r = check_players_level(t->teams[i].players);
        if (r == 1)
            break;
    }
    if (r == 0)
        return (0);
    for (int i = 0; i < t->nbts; i++) {
        r = check_players_level(t->teams[i].players);
        says_players_result(t->teams[i].players, r);
    }
    seg(t);
    return (1);
}