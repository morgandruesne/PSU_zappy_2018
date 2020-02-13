/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** incantation error cmd
*/

#include "../../../include/server.h"

current_t *error_inc(current_t *t, int fd, char **cmd, inv_t *inv)
{
    dprintf(fd, "ko\n");
    ftab(cmd);
    free(inv->objects);
    return (t);
}

current_t *error_incd(current_t *t, int fd, char **cmd, inv_t *inv)
{
    dprintf(fd, "ko\nko\n");
    ftab(cmd);
    free(inv->objects);
    return (t);
}