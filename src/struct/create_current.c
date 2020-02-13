/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** create_current
*/

#include "../../include/server.h"

current_t *create_current(void)
{
    current_t *t = malloc(sizeof(*t));

    if (t == NULL)
        return (NULL);
    t->map = create_map(10, 10);
    t->ser._socket = -1;
    t->ser._graphfd = -1;
    t->ser._port = 4242;
    t->ser._freq = 100;
    t->ser._fds = NULL;
    t->nbts = 0;
    t->nbc = 3;
    t->teams = NULL;
    return (t);
}