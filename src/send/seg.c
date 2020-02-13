/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** seg send
*/

#include "../../include/server.h"

current_t *seg(current_t *t)
{
    if (t->ser._graphfd != -1)
        dprintf(t->ser._graphfd, "seg\n");
    return (t);
}