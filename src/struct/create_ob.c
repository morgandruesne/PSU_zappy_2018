/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** create_ob
*/

#include "../../include/server.h"

ob_t create_ob(char *name, int nb)
{
    ob_t t;

    if (name == NULL)
        t.name = NULL;
    else
        t.name = strdup(name);
    t.nb = nb;
    return (t);
}