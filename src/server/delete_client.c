/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** delete client server
*/

#include "../../include/server.h"

int *supr_client_toteam(int *clients, int fdc, int size)
{
    for (int i = 0; i < size; i++) {
        if (clients[i] == fdc) {
            clients[i] = -1;
            break;
        }
    }
    for (int i = 0; i < size - 1; i++) {
        if (clients[i] == -1 && clients[i + 1] != -1) {
            clients[i] = clients[i + 1];
            clients[i + 1] = -1;
        }
    }
    return (clients);
}

int *add_client_toteam(int *clients, int fdc, int size)
{
    for (int i = 0; i < size; i++) {
        if (clients[i] == -1) {
            clients[i] = fdc;
            return (clients);
        }
    }
    return (clients);
}

current_t *delete_client(current_t *t, lst_t *target)
{
    int it = -1;

    if ((it = target->nb_team) != -1)
        t = death(t, target, NULL);
    else {
        close(target->fd);
        t->ser._fds = delete_lst_node(t->ser._fds, target);
    }
    return (t);
}