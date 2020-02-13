/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** player_t function
*/

#include "../../include/server.h"

char get_player_rby(player_t *t)
{
    switch (t->r)
    {
        case 0:
            return ('N');
        case 30:
            return ('E');
        case 60:
            return ('S');
        case 90:
            return ('W');
        default:
            return ('\0');
    }
}

player_t *get_player_bynbp(player_t *lst, int fd)
{
    player_t *tmp;

    tmp = lst;
    while (tmp != NULL) {
        printf("%d\n", tmp->nb);
        if (tmp->nb == fd)
            return (tmp);
        tmp = tmp->n;
    }
    return (NULL);
}