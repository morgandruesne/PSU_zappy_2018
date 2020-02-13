/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** lst_t
*/

#include "../../include/server.h"

lst_t *create_lst(int fd)
{
    lst_t *t;

    t = malloc(sizeof(*t));
    if (t == NULL)
        return (NULL);
    t->fd = fd;
    t->nb_team = -1;
    t->lifes = 10;
    t->n = NULL;
    return (t);
}

lst_t *push_lst(lst_t *list, lst_t *t)
{
    lst_t *tmp;

    if (list == NULL)
        return (t);
    tmp = list;
    while (tmp->n != NULL)
        tmp = tmp->n;
    tmp->n = t;
    return (list);
}

void delete_lst(lst_t *list)
{
    lst_t *tmp;

    tmp = list;
    while (tmp != NULL) {
        list = list->n;
        free(tmp);
        tmp = list;
    }
}

lst_t *delete_lst_node(lst_t *list, lst_t *l)
{
    lst_t *tmp;

    if (l == list) {
        tmp = l->n;
        free(l);
        return (tmp);
    }
    tmp = list;
    while (tmp != NULL) {
        if (tmp->n == l) {
            tmp->n = tmp->n->n;
            free(l);
            return (list);
        }
    }
    return (list);
}

lst_t *get_lst_byfd(lst_t *lst, int fd)
{
    lst_t *tmp;

    tmp = lst;
    while (tmp != NULL) {
        if (tmp->fd == fd)
            return (tmp);
        tmp = tmp->n;
    }
    return (NULL);
}