/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** player_t
*/

#include "../../include/server.h"

player_t *create_player(int fd)
{
    player_t *t;
    static int nba = 0;

    t = malloc(sizeof(*t));
    if (t == NULL)
        return (NULL);
    t->master = fd;
    t->level = 1;
    t->r = 0;
    t->inv = create_inv_int(0);
    t->inv.objects[0].nb = 10;
    t->x = 0;
    t->y = 0;
    t->nb = nba;
    nba++;
    t->lifes = 10;
    t->st = 1;
    t->n = NULL;
    return (t);
}

player_t *push_player(player_t *list, player_t *t)
{
    player_t *tmp;

    if (list == NULL)
        return (t);
    tmp = list;
    while (tmp->n != NULL)
        tmp = tmp->n;
    tmp->n = t;
    return (list);
}

void delete_player(player_t *list)
{
    player_t *tmp;

    tmp = list;
    while (tmp != NULL) {
        list = list->n;
        free(tmp);
        tmp = list;
    }
}

player_t *delete_player_node(player_t *list, player_t *l)
{
    player_t *tmp;

    if (l == list) {
        tmp = l->n;
        free(l);
        return (tmp);
    }
    tmp = list;
    while (tmp != NULL) {
        if (tmp->n == l) {
            tmp->n = tmp->n->n;
            free(l->inv.objects);
            free(l);
            return (list);
        }
    }
    return (list);
}

player_t *get_player_byfd(player_t *lst, int fd)
{
    player_t *tmp;

    tmp = lst;
    while (tmp != NULL) {
        if (tmp->master == fd)
            return (tmp);
        tmp = tmp->n;
    }
    return (NULL);
}