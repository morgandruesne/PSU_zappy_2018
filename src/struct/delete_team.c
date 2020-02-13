/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** delete_team
*/

#include "../../include/server.h"

void delete_team(team_t *t)
{
    for (int i = 0; i < t->nb; i++) {
        if (t->clients[i] != -1)
            close(t->clients[i]);
    }
    free(t->clients);
    delete_player(t->players);
}