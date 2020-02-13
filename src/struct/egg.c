/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** egg_t
*/

#include "../../include/server.h"

egg_t *create_egg(int nbteam)
{
    egg_t *t;
    static int i = 0;

    t = malloc(sizeof(*t));
    if (t == NULL)
        return (NULL);
    t->nb_team = nbteam;
    t->nb = i;
    i++;
    t->time = 6;
    t->nbc = -1;
    t->x = 0;
    t->y = 0;
    t->n = NULL;
    return (t);
}

egg_t *push_egg(egg_t *list, egg_t *t)
{
    egg_t *tmp;

    if (list == NULL)
        return (t);
    tmp = list;
    while (tmp->n != NULL)
        tmp = tmp->n;
    tmp->n = t;
    return (list);
}

void delete_egg(egg_t *list)
{
    egg_t *tmp;

    tmp = list;
    while (tmp != NULL) {
        list = list->n;
        free(tmp);
        tmp = list;
    }
}

egg_t *delete_egg_node(egg_t *list, egg_t *l)
{
    egg_t *tmp;

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