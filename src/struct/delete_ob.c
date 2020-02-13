/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** delete_ob
*/

#include "../../include/server.h"

void delete_ob(ob_t ob)
{
    if (ob.name != NULL)
        free(ob.name);
}