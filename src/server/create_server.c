/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** create server
*/

#include "../../include/server.h"

int initiation_server(server_t *t)
{
    t->_sckk.sin_family = AF_INET;
    t->_sckk.sin_port = htons(t->_port);
    t->_sckk.sin_addr.s_addr = INADDR_ANY;
    t->_sckk_size = sizeof(t->_sckk);
    if ((t->_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        return (return_m("server error : socket", -1, 2));
    if (bind(t->_socket, (struct sockaddr *)&t->_sckk,
    t->_sckk_size) == -1)
        return (return_m("server error : bind", -1, 2));
    if (listen(t->_socket, 100) == -1)
        return (return_m("server error : listen", -1, 2));
    return (0);
}

void fd_set_clients(lst_t *list, fd_set *w)
{
    lst_t *tmp;

    if (list == NULL)
        return;
    tmp = list;
    while (tmp != NULL) {
        FD_SET(tmp->fd, w);
        tmp = tmp->n;
    }
}

int check_current(current_t *t)
{
    if (t->map.x < 10 || t->map.y < 10)
        return (84);
    if (t->nbc <= 0)
        return (84);
    if (t->ser._freq <= 0)
        return (84);
    if (t->ser._port <= 0)
        return (84);
    return (0);
}
