/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** eht send
*/

#include "../../include/server.h"

current_t *eht(current_t *t, egg_t *egg)
{
    if (t->ser._graphfd != -1)
        dprintf(t->ser._graphfd, "eht %d\n", egg->nb);
    return (t);
}