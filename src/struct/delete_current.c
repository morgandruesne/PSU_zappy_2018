/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** delete_current
*/

#include "../../include/server.h"

void delete_current(current_t *t)
{
    if (t->ser._socket != -1)
        close(t->ser._socket);
    delete_lst(t->ser._fds);
    if (t->nbts != 0) {
        for (int i = 0; i < t->nbts; i++)
            delete_team(&t->teams[i]);
        free(t->teams);
    }
    free(t);
}