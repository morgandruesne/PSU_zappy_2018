/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** incantation cmd
*/

#include "../../../include/server.h"

int get_linemate(int l)
{
    if (l == 4 || l == 8)
        return (2);
    return (1);
}

int get_player(int l)
{
    if (l == 2)
        return (1);
    if (l == 3 || l == 4)
        return (2);
    if (l == 5 || l == 6)
        return (4);
    return (6);
}