/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** my returns
*/

#include "../include/server.h"

void exit_p(current_t *t, char *msg, int r, int fd)
{
    delete_current(t);
    dprintf(fd, "%s\n", msg);
    exit(r);
}

int return_p(current_t *t, char *msg, int r, int fd)
{
    delete_current(t);
    dprintf(fd, "%s\n", msg);
    return (r);
}

int return_m(char *msg, int r, int fd)
{
    dprintf(fd, "%s\n", msg);
    return (r);
}