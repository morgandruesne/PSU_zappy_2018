/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** get_team
*/

#include "../../include/server.h"

int get_team_byname(current_t *t, char *str)
{
    for (int i = 0; i < t->nbts; i++) {
        if (strcmp(str, t->teams[i].name) == 0)
            return (i);
    }
    return (-1);
}

int get_team_nbp(int *players, int size)
{
    for (int i = 0; i < size; i++) {
        if (players[i] == -1)
            return (i);
    }
    return (size);
}